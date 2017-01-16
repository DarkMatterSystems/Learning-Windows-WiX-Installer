
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* File State Actions */

void adm_state_action_file_generating(
    adm_ent_file_typ * ent_file)
{
    /* Entity Objects */
    adm_ent_file_shortcut_typ * ent_file_shortcut_0000000001;

    /* Relationship Relations */
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_file_generating");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<File");
    adm_template_tab_in(1, 956, 37);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_file->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Name='");
    adm_write_str(ent_file->atb_name);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("DiskId='1'");
    adm_write_newline();
    adm_write_str("Source='");
    adm_write_str(ent_file->atb_source);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("KeyPath='yes'");

    /* Traverse - TraverseSelection */

    adm_object_existent_file(
        ent_file,
        1, 967, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_file_includes_file_shortcut_0000000001 = ent_file->rel_includes_file_shortcut_head;

    while (rel_file_includes_file_shortcut_0000000001 != NULL) {

        ent_file_shortcut_0000000001 = rel_file_includes_file_shortcut_0000000001->ent_file_shortcut;

        traverse_not_found_0000000002 = FALSE;

        /* SelectionHead */

        adm_object_existent_file(
            ent_file,
            1, 967, 45);

        if (rel_file_includes_file_shortcut_0000000001 == ent_file->rel_includes_file_shortcut_head) {

            /* Template */

            adm_write_str(">");
        }

        rel_file_includes_file_shortcut_0000000001 = rel_file_includes_file_shortcut_0000000001->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Template */

        adm_write_str("/>");
    }

    /* GenerateEvent */

    adm_send_event_file_generate_file_shortcut(
        ent_file,
        ent_file,
        1, 976, 41);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_file_generating");
    #endif
}

void adm_state_action_file_generating_file_shortcut(
    adm_ent_file_typ * ent_file)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_file_shortcut_typ * ent_file_shortcut_0000000001;

    /* Relationship Relations */
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_file_generating_file_shortcut");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_file(
        ent_file,
        1, 996, 45);

    rel_file_includes_file_shortcut_0000000001 = ent_file->rel_includes_file_shortcut_head;

    while (rel_file_includes_file_shortcut_0000000001 != NULL) {

        ent_file_shortcut_0000000001 = rel_file_includes_file_shortcut_0000000001->ent_file_shortcut;

        /* CaseSelection */

        if (
            (
                (
                    pdt_object_not_found
                )
                &&
                !(
                    ent_file_shortcut_0000000001->atb_processed
                )
            )) {

            /* Assignment - Set */

            pdt_object_not_found = FALSE;

            /* Assignment - Set */

            ent_file_shortcut_0000000001->atb_processed = TRUE;

            /* Relate */

            adm_link_relation_file_shortcut_writing_file(
                ent_file_shortcut_0000000001,
                ent_file,
                1, 1011, 61);

            /* GenerateEvent */

            adm_send_event_file_shortcut_generate(
                ent_file,
                ent_file_shortcut_0000000001,
                1, 1013, 61);
        }

        rel_file_includes_file_shortcut_0000000001 = rel_file_includes_file_shortcut_0000000001->next;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_object_not_found
            )
        )) {

        /* GenerateEvent */

        adm_send_event_file_complete(
            ent_file,
            ent_file,
            1, 1021, 53);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_file_generating_file_shortcut");
    #endif
}

void adm_state_action_file_idle(
    adm_ent_file_typ * ent_file)
{
    /* Entity Objects */
    adm_ent_file_shortcut_typ * ent_file_shortcut_0000000001;
    adm_ent_component_typ * ent_component_0000000003;

    /* Relationship Relations */
    adm_rel_file_includes_file_shortcut_typ * rel_file_includes_file_shortcut_0000000001;
    adm_rel_file_writing_component_typ * rel_file_writing_component_0000000003;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_file_idle");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_file(
        ent_file,
        1, 1036, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_file_includes_file_shortcut_0000000001 = ent_file->rel_includes_file_shortcut_head;

    while (rel_file_includes_file_shortcut_0000000001 != NULL) {

        ent_file_shortcut_0000000001 = rel_file_includes_file_shortcut_0000000001->ent_file_shortcut;

        traverse_not_found_0000000002 = FALSE;

        /* SelectionHead */

        adm_object_existent_file(
            ent_file,
            1, 1036, 45);

        if (rel_file_includes_file_shortcut_0000000001 == ent_file->rel_includes_file_shortcut_head) {

            /* Template */

            adm_write_newline();
            adm_template_tab_out(1, 1039, 49);
            adm_write_newline();
            adm_write_str("</File>");
        }

        rel_file_includes_file_shortcut_0000000001 = rel_file_includes_file_shortcut_0000000001->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Template */

        adm_template_tab_out(1, 1044, 45);
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_file(
        ent_file,
        1, 1048, 45);

    rel_file_writing_component_0000000003 = ent_file->rel_writing_component_head;

    if (rel_file_writing_component_0000000003 != NULL) {

        ent_component_0000000003 = rel_file_writing_component_0000000003->ent_component;

        /* Unrelate */

        adm_kill_relation_file_writing_component(
            ent_file,
            rel_file_writing_component_0000000003,
            1, 1051, 49);

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_file,
            ent_component_0000000003,
            1, 1053, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_file_idle");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */