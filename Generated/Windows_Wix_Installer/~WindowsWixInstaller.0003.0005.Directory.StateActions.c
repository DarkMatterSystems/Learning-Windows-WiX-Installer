
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* Directory State Actions */

void adm_state_action_directory_display_heading(
    adm_ent_directory_typ * ent_directory)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_display_heading");
    #endif

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_directory->atb_heading, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_newline();
        adm_write_str("<!-- ");
        adm_write_str(ent_directory->atb_heading);
        adm_write_str(" -->");
    }

    /* GenerateEvent */

    adm_send_event_directory_generate(
        ent_directory,
        ent_directory,
        1, 472, 41);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_display_heading");
    #endif
}

void adm_state_action_directory_generating(
    adm_ent_directory_typ * ent_directory)
{
    /* Entity Objects */
    adm_ent_component_typ * ent_component_0000000001;
    adm_ent_directory_typ * ent_directory_0000000003;

    /* Relationship Relations */
    adm_rel_directory_includes_component_typ * rel_directory_includes_component_0000000001;
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory_0000000003;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;
    adm_base_boolean_typ traverse_not_found_0000000004;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_generating");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Directory");
    adm_template_tab_in(1, 486, 37);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_directory->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Name='");
    adm_write_str(ent_directory->atb_name);
    adm_write_str("'");

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory,
        1, 494, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_directory_includes_component_0000000001 = ent_directory->rel_includes_component_head;

    while (rel_directory_includes_component_0000000001 != NULL) {

        ent_component_0000000001 = rel_directory_includes_component_0000000001->ent_component;

        traverse_not_found_0000000002 = FALSE;

        /* SelectionHead */

        adm_object_existent_directory(
            ent_directory,
            1, 494, 45);

        if (rel_directory_includes_component_0000000001 == ent_directory->rel_includes_component_head) {

            /* Template */

            adm_write_str(">");

            /* GenerateEvent */

            adm_send_event_directory_generate_component(
                ent_directory,
                ent_directory,
                1, 500, 53);
        }

        rel_directory_includes_component_0000000001 = rel_directory_includes_component_0000000001->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Traverse - TraverseSelection */

        adm_object_existent_directory(
            ent_directory,
            1, 504, 53);

        traverse_not_found_0000000004 = TRUE;

        rel_directory_includes_directory_0000000003 = ent_directory->rel_includes_directory_head;

        while (rel_directory_includes_directory_0000000003 != NULL) {

            ent_directory_0000000003 = rel_directory_includes_directory_0000000003->ent_directory;

            traverse_not_found_0000000004 = FALSE;

            /* SelectionHead */

            adm_object_existent_directory(
                ent_directory_0000000003,
                1, 504, 53);

            if (rel_directory_includes_directory_0000000003 == ent_directory->rel_includes_directory_head) {

                /* Template */

                adm_write_str(">");

                /* GenerateEvent */

                adm_send_event_directory_generate_directory(
                    ent_directory,
                    ent_directory,
                    1, 510, 61);
            }

            rel_directory_includes_directory_0000000003 = rel_directory_includes_directory_0000000003->next;
        }

        /* Traverse - Null Traverse Selection */

        if (traverse_not_found_0000000004) {

            /* Template */

            adm_write_str("/>");

            /* GenerateEvent */

            adm_send_event_directory_complete(
                ent_directory,
                ent_directory,
                1, 515, 57);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_generating");
    #endif
}

void adm_state_action_directory_generating_component(
    adm_ent_directory_typ * ent_directory)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_component_typ * ent_component_0000000001;

    /* Relationship Relations */
    adm_rel_directory_includes_component_typ * rel_directory_includes_component_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_generating_component");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory,
        1, 536, 45);

    rel_directory_includes_component_0000000001 = ent_directory->rel_includes_component_head;

    while (rel_directory_includes_component_0000000001 != NULL) {

        ent_component_0000000001 = rel_directory_includes_component_0000000001->ent_component;

        /* CaseSelection */

        if (
            (
                (
                    pdt_object_not_found
                )
                &&
                !(
                    ent_component_0000000001->atb_processed
                )
            )) {

            /* Assignment - Set */

            pdt_object_not_found = FALSE;

            /* Assignment - Set */

            ent_component_0000000001->atb_processed = TRUE;

            /* Relate */

            adm_link_relation_component_writing_directory(
                ent_component_0000000001,
                ent_directory,
                1, 551, 61);

            /* GenerateEvent */

            adm_send_event_component_generate(
                ent_directory,
                ent_component_0000000001,
                1, 553, 61);
        }

        rel_directory_includes_component_0000000001 = rel_directory_includes_component_0000000001->next;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_object_not_found
            )
        )) {

        /* GenerateEvent */

        adm_send_event_directory_complete(
            ent_directory,
            ent_directory,
            1, 561, 53);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_generating_component");
    #endif
}

void adm_state_action_directory_generating_directory(
    adm_ent_directory_typ * ent_directory)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_directory_typ * ent_directory_0000000001;

    /* Relationship Relations */
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_generating_directory");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory,
        1, 582, 45);

    rel_directory_includes_directory_0000000001 = ent_directory->rel_includes_directory_head;

    while (rel_directory_includes_directory_0000000001 != NULL) {

        ent_directory_0000000001 = rel_directory_includes_directory_0000000001->ent_directory;

        /* CaseSelection */

        if (
            (
                (
                    pdt_object_not_found
                )
                &&
                !(
                    ent_directory_0000000001->atb_processed
                )
            )) {

            /* Assignment - Set */

            pdt_object_not_found = FALSE;

            /* Assignment - Set */

            ent_directory_0000000001->atb_processed = TRUE;

            /* Relate */

            adm_link_relation_directory_writing_directory(
                ent_directory_0000000001,
                ent_directory,
                1, 597, 61);

            /* GenerateEvent */

            adm_send_event_directory_generate(
                ent_directory,
                ent_directory_0000000001,
                1, 599, 61);
        }

        rel_directory_includes_directory_0000000001 = rel_directory_includes_directory_0000000001->next;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_object_not_found
            )
        )) {

        /* GenerateEvent */

        adm_send_event_directory_complete(
            ent_directory,
            ent_directory,
            1, 607, 53);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_generating_directory");
    #endif
}

void adm_state_action_directory_idle(
    adm_ent_directory_typ * ent_directory)
{
    /* Entity Objects */
    adm_ent_component_typ * ent_component_0000000001;
    adm_ent_directory_typ * ent_directory_0000000003;
    adm_ent_directory_typ * ent_directory_0000000005;
    adm_ent_product_typ * ent_product_0000000007;

    /* Relationship Relations */
    adm_rel_directory_includes_component_typ * rel_directory_includes_component_0000000001;
    adm_rel_directory_includes_directory_typ * rel_directory_includes_directory_0000000003;
    adm_rel_directory_writing_directory_typ * rel_directory_writing_directory_0000000005;
    adm_rel_directory_writing_product_typ * rel_directory_writing_product_0000000007;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;
    adm_base_boolean_typ traverse_not_found_0000000004;
    adm_base_boolean_typ traverse_not_found_0000000006;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_idle");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory,
        1, 623, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_directory_includes_component_0000000001 = ent_directory->rel_includes_component_head;

    while (rel_directory_includes_component_0000000001 != NULL) {

        ent_component_0000000001 = rel_directory_includes_component_0000000001->ent_component;

        traverse_not_found_0000000002 = FALSE;

        /* SelectionHead */

        adm_object_existent_directory(
            ent_directory,
            1, 623, 45);

        if (rel_directory_includes_component_0000000001 == ent_directory->rel_includes_component_head) {

            /* Template */

            adm_write_newline();
            adm_template_tab_out(1, 626, 49);
            adm_write_newline();
            adm_write_str("</Directory>");
        }

        rel_directory_includes_component_0000000001 = rel_directory_includes_component_0000000001->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Traverse - TraverseSelection */

        adm_object_existent_directory(
            ent_directory,
            1, 633, 53);

        traverse_not_found_0000000004 = TRUE;

        rel_directory_includes_directory_0000000003 = ent_directory->rel_includes_directory_head;

        while (rel_directory_includes_directory_0000000003 != NULL) {

            ent_directory_0000000003 = rel_directory_includes_directory_0000000003->ent_directory;

            traverse_not_found_0000000004 = FALSE;

            /* SelectionHead */

            adm_object_existent_directory(
                ent_directory_0000000003,
                1, 633, 53);

            if (rel_directory_includes_directory_0000000003 == ent_directory->rel_includes_directory_head) {

                /* Template */

                adm_write_newline();
                adm_template_tab_out(1, 636, 57);
                adm_write_newline();
                adm_write_str("</Directory>");
            }

            rel_directory_includes_directory_0000000003 = rel_directory_includes_directory_0000000003->next;
        }

        /* Traverse - Null Traverse Selection */

        if (traverse_not_found_0000000004) {

            /* Template */

            adm_template_tab_out(1, 641, 53);
        }
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_directory(
        ent_directory,
        1, 645, 45);

    traverse_not_found_0000000006 = TRUE;

    rel_directory_writing_directory_0000000005 = ent_directory->rel_writing_directory_head;

    if (rel_directory_writing_directory_0000000005 != NULL) {

        ent_directory_0000000005 = rel_directory_writing_directory_0000000005->ent_directory;

        traverse_not_found_0000000006 = FALSE;

        /* Unrelate */

        adm_kill_relation_directory_writing_directory(
            ent_directory,
            rel_directory_writing_directory_0000000005,
            1, 648, 49);

        /* GenerateEvent */

        adm_send_event_directory_done(
            ent_directory,
            ent_directory_0000000005,
            1, 650, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000006) {

        /* Traverse - TraverseSelection */

        adm_object_existent_directory(
            ent_directory,
            1, 654, 53);

        rel_directory_writing_product_0000000007 = ent_directory->rel_writing_product_head;

        if (rel_directory_writing_product_0000000007 != NULL) {

            ent_product_0000000007 = rel_directory_writing_product_0000000007->ent_product;

            /* Unrelate */

            adm_kill_relation_directory_writing_product(
                ent_directory,
                rel_directory_writing_product_0000000007,
                1, 657, 57);

            /* GenerateEvent */

            adm_send_event_product_complete(
                ent_directory,
                ent_product_0000000007,
                1, 659, 57);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_directory_idle");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */