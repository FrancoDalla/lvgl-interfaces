/*
Flujo basico:
    1->Inicializar los driver para utilizar reloj, temporizadores, perifericos, etc.
    2->Llamar lv_init(), esto inicializa LVGL.
    3->Crear display(s) y los dispositivos de entrada, también hacer sus callbacks.
    4->Crear la interfaz de usuario en si.
    5->Llamar a lv_timer_handler() en loop, este se encarga de tareas relacionadas a LVGL tales como:
        -Refrescar los display.
        -Leer dispositivos de entrada.
        -Correr animaciones.
        -etc.
*/
#include <stdlib.h>
#include <stdio.h>
#include "lvgl/lvgl.h"
#include <SDL.h>


#include "lvgl/demos/lv_demos.h"
#include "lvgl/examples/lv_examples.h"
#include "./vistas/vistas.h"


static lv_display_t * hal_init(int32_t w, int32_t h);

void main(void){
    lv_init();

    hal_init(320, 240);

    principal();

    while(1){
        lv_timer_handler();
    }


}


/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static lv_display_t * hal_init(int32_t w, int32_t h)
{

  lv_group_set_default(lv_group_create());

  lv_display_t * disp = lv_sdl_window_create(w, h);

  lv_indev_t * mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_display(mouse, disp);
  lv_display_set_default(disp);

  LV_IMAGE_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj;
  cursor_obj = lv_image_create(lv_screen_active()); /*Create an image object for the cursor */
  lv_image_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/

  lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
  lv_indev_set_display(mousewheel, disp);
  lv_indev_set_group(mousewheel, lv_group_get_default());

  lv_indev_t * kb = lv_sdl_keyboard_create();
  lv_indev_set_display(kb, disp);
  lv_indev_set_group(kb, lv_group_get_default());

  return disp;
}
