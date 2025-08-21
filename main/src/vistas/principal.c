#include "../../../lvgl/examples/lv_examples.h"
#include <strings.h>
#include "vistas.h"
#define ELEMENTOS 3

#if LV_USE_FLEX && LV_BUILD_EXAMPLES


void principal(void)
{
    /*Limpia la pantalla */
    lv_obj_clean(lv_screen_active());


    /*Contenedor con flex-direction en columna*/
    lv_obj_t * contenedor_columna = lv_obj_create(lv_screen_active());
    lv_obj_set_size(contenedor_columna, 200, 150);
    lv_obj_align_to(contenedor_columna, NULL, LV_ALIGN_CENTER, 0, 5);
    lv_obj_set_flex_flow(contenedor_columna, LV_FLEX_FLOW_COLUMN);

    char *texto_botones[] = {"Iniciar", "Configuraciones", "Apagar"};
    void (*funciones[])() = {NULL, configuracion, NULL};

    uint32_t i;

    for(i = 0; i < 3; i++){
        lv_obj_t *obj;
        lv_obj_t *label;


        /*Agregar objetos a la columna. En este caso botones*/
        obj = lv_button_create(contenedor_columna);
        lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);

        lv_obj_add_event_cb(obj, funciones[i], LV_EVENT_CLICKED, NULL);
        label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "%s", texto_botones[i]);
        lv_obj_center(label);
    }
}

#endif
