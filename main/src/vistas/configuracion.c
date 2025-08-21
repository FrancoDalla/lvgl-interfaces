#include "../../../lvgl/examples/lv_examples.h"
#include <strings.h>
#include "vistas.h"

#define ELEMENTOS 2

#if LV_USE_FLEX && LV_BUILD_EXAMPLES



void configuracion(void)
{
    /*Limpia la pantalla */
    lv_obj_clean(lv_screen_active());

    /*Contenedor con flex-direction en columna*/
    lv_obj_t * contenedor_fila = lv_obj_create(lv_screen_active());
    lv_obj_set_size(contenedor_fila, LV_PCT(100), LV_PCT(70));
    lv_obj_align_to(contenedor_fila, NULL, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_flex_flow(contenedor_fila, LV_FLEX_FLOW_ROW);


    char *texto_botones[] = {"accion 1", "accion 2"};
    void (*volver)() = principal;

    uint32_t i;

    for(i = 0; i < ELEMENTOS; i++){
        lv_obj_t *obj;
        lv_obj_t *label;


        /*Agregar objetos a la columna*/
        obj = lv_button_create(contenedor_fila);
        lv_obj_set_size(obj, LV_PCT(50), LV_PCT(50));

        label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "%s", texto_botones[i]);
        lv_obj_center(label);
    }

    /*Contenedor con boton para volver atras*/
    lv_obj_t * contenedor_inferior = lv_obj_create(lv_screen_active());
    lv_obj_set_size(contenedor_inferior, LV_PCT(100), LV_PCT(30));
    lv_obj_align_to(contenedor_inferior, NULL, LV_ALIGN_BOTTOM_LEFT,0,0);

    lv_obj_t *obj_volver;
    lv_obj_t *label_volver;

    obj_volver = lv_button_create(contenedor_inferior);
    lv_obj_set_size(obj_volver, LV_PCT(30), LV_PCT(100));

    label_volver = lv_label_create(obj_volver);
    lv_label_set_text_fmt(label_volver, "Volver");
    lv_obj_center(label_volver);
    lv_obj_add_event_cb(obj_volver, volver, LV_EVENT_CLICKED, NULL);


}

#endif
