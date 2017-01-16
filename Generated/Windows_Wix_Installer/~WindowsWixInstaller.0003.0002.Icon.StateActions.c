
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* Icon State Actions */

void adm_state_action_icon_generating(
    adm_ent_icon_typ * ent_icon)
{
    /* Entity Objects */
    adm_ent_product_typ * ent_product_0000000001;

    /* Relationship Relations */
    adm_rel_icon_writing_product_typ * rel_icon_writing_product_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_icon_generating");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Icon");
    adm_template_tab_in(1, 336, 37);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_icon->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("SourceFile='");
    adm_write_str(ent_icon->atb_source_file);
    adm_write_str("'/>");
    adm_template_tab_out(1, 336, 37);

    /* Traverse - TraverseSelection */

    adm_object_existent_icon(
        ent_icon,
        1, 345, 45);

    rel_icon_writing_product_0000000001 = ent_icon->rel_writing_product_head;

    if (rel_icon_writing_product_0000000001 != NULL) {

        ent_product_0000000001 = rel_icon_writing_product_0000000001->ent_product;

        /* Unrelate */

        adm_kill_relation_icon_writing_product(
            ent_icon,
            rel_icon_writing_product_0000000001,
            1, 348, 49);

        /* GenerateEvent */

        adm_send_event_product_done(
            ent_icon,
            ent_product_0000000001,
            1, 350, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_icon_generating");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */