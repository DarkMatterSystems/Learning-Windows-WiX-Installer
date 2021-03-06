
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* Feature State Actions */

void adm_state_action_feature_display_heading(
    adm_ent_feature_typ * ent_feature)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_display_heading");
    #endif

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature->atb_heading, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_newline();
        adm_write_str("<!-- ");
        adm_write_str(ent_feature->atb_heading);
        adm_write_str(" -->");
    }

    /* GenerateEvent */

    adm_send_event_feature_generate(
        ent_feature,
        ent_feature,
        1, 1437, 41);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_display_heading");
    #endif
}

void adm_state_action_feature_generating(
    adm_ent_feature_typ * ent_feature)
{
    /* Entity Objects */
    adm_ent_feature_typ * ent_feature_0000000001;
    adm_ent_component_typ * ent_component_0000000003;
    adm_ent_component_typ * ent_component_0000000004;

    /* Relationship Relations */
    adm_rel_feature_includes_feature_typ * rel_feature_includes_feature_0000000001;
    adm_rel_feature_includes_component_typ * rel_feature_includes_component_0000000003;
    adm_rel_feature_includes_component_typ * rel_feature_includes_component_0000000004;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_generating");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Feature");
    adm_template_tab_in(1, 1451, 37);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_feature->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Title='");
    adm_write_str(ent_feature->atb_title);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Level='1'");

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature->atb_description, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("Description='");
        adm_write_str(ent_feature->atb_description);
        adm_write_str("'");
    }

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature->atb_display, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("Display='");
        adm_write_str(ent_feature->atb_display);
        adm_write_str("'");
    }

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_feature->atb_configurable_directory, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("ConfigurableDirectory='");
        adm_write_str(ent_feature->atb_configurable_directory);
        adm_write_str("'");
    }

    /* Template */

    adm_write_str(">");

    /* Traverse - TraverseSelection */

    adm_object_existent_feature(
        ent_feature,
        1, 1486, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_feature_includes_feature_0000000001 = ent_feature->rel_includes_feature_head;

    while (rel_feature_includes_feature_0000000001 != NULL) {

        ent_feature_0000000001 = rel_feature_includes_feature_0000000001->ent_feature;

        traverse_not_found_0000000002 = FALSE;

        /* SelectionHead */

        adm_object_existent_feature(
            ent_feature_0000000001,
            1, 1486, 45);

        if (rel_feature_includes_feature_0000000001 == ent_feature->rel_includes_feature_head) {

            /* GenerateEvent */

            adm_send_event_feature_generate_feature(
                ent_feature,
                ent_feature,
                1, 1490, 53);
        }

        rel_feature_includes_feature_0000000001 = rel_feature_includes_feature_0000000001->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Traverse - TraverseSelection */

        adm_object_existent_feature(
            ent_feature,
            1, 1494, 53);

        rel_feature_includes_component_0000000003 = ent_feature->rel_includes_component_head;

        while (rel_feature_includes_component_0000000003 != NULL) {

            ent_component_0000000003 = rel_feature_includes_component_0000000003->ent_component;

            /* SelectionHead */

            adm_object_existent_feature(
                ent_feature,
                1, 1494, 53);

            if (rel_feature_includes_component_0000000003 == ent_feature->rel_includes_component_head) {

                /* Template */

                adm_write_newline();

                /* Traverse - TraverseSelection */

                adm_object_existent_feature(
                    ent_feature,
                    1, 1501, 65);

                rel_feature_includes_component_0000000004 = ent_feature->rel_includes_component_head;

                while (rel_feature_includes_component_0000000004 != NULL) {

                    ent_component_0000000004 = rel_feature_includes_component_0000000004->ent_component;

                    /* Assignment - Set */

                    ent_component_0000000004->atb_processed = FALSE;

                    rel_feature_includes_component_0000000004 = rel_feature_includes_component_0000000004->next;
                }

                /* GenerateEvent */

                adm_send_event_feature_generate_component(
                    ent_feature,
                    ent_feature,
                    1, 1507, 61);
            }

            rel_feature_includes_component_0000000003 = rel_feature_includes_component_0000000003->next;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_generating");
    #endif
}

void adm_state_action_feature_generating_feature(
    adm_ent_feature_typ * ent_feature)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_feature_typ * ent_feature_0000000001;

    /* Relationship Relations */
    adm_rel_feature_includes_feature_typ * rel_feature_includes_feature_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_generating_feature");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_feature(
        ent_feature,
        1, 1528, 45);

    rel_feature_includes_feature_0000000001 = ent_feature->rel_includes_feature_head;

    while (rel_feature_includes_feature_0000000001 != NULL) {

        ent_feature_0000000001 = rel_feature_includes_feature_0000000001->ent_feature;

        /* CaseSelection */

        if (
            (
                (
                    pdt_object_not_found
                )
                &&
                !(
                    ent_feature_0000000001->atb_processed
                )
            )) {

            /* Assignment - Set */

            pdt_object_not_found = FALSE;

            /* Assignment - Set */

            ent_feature_0000000001->atb_processed = TRUE;

            /* Relate */

            adm_link_relation_feature_writing_feature(
                ent_feature_0000000001,
                ent_feature,
                1, 1543, 61);

            /* GenerateEvent */

            adm_send_event_feature_generate(
                ent_feature,
                ent_feature_0000000001,
                1, 1545, 61);
        }

        rel_feature_includes_feature_0000000001 = rel_feature_includes_feature_0000000001->next;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_object_not_found
            )
        )) {

        /* GenerateEvent */

        adm_send_event_feature_complete(
            ent_feature,
            ent_feature,
            1, 1553, 53);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_generating_feature");
    #endif
}

void adm_state_action_feature_finishing_product_feature(
    adm_ent_feature_typ * ent_feature)
{
    /* Entity Objects */
    adm_ent_product_typ * ent_product_0000000001;

    /* Relationship Relations */
    adm_rel_feature_writing_product_typ * rel_feature_writing_product_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_finishing_product_feature");
    #endif

    /* Template */

    adm_write_newline();
    adm_template_tab_out(1, 1567, 37);
    adm_write_newline();
    adm_write_str("</Feature>");

    /* Traverse - TraverseSelection */

    adm_object_existent_feature(
        ent_feature,
        1, 1573, 45);

    rel_feature_writing_product_0000000001 = ent_feature->rel_writing_product_head;

    if (rel_feature_writing_product_0000000001 != NULL) {

        ent_product_0000000001 = rel_feature_writing_product_0000000001->ent_product;

        /* Unrelate */

        adm_kill_relation_feature_writing_product(
            ent_feature,
            rel_feature_writing_product_0000000001,
            1, 1576, 49);

        /* GenerateEvent */

        adm_send_event_product_complete(
            ent_feature,
            ent_product_0000000001,
            1, 1578, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_finishing_product_feature");
    #endif
}

void adm_state_action_feature_generating_component(
    adm_ent_feature_typ * ent_feature)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_component_typ * ent_component_0000000001;

    /* Relationship Relations */
    adm_rel_feature_includes_component_typ * rel_feature_includes_component_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_generating_component");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_feature(
        ent_feature,
        1, 1598, 45);

    rel_feature_includes_component_0000000001 = ent_feature->rel_includes_component_head;

    while (rel_feature_includes_component_0000000001 != NULL) {

        ent_component_0000000001 = rel_feature_includes_component_0000000001->ent_component;

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

            adm_link_relation_component_writing_feature(
                ent_component_0000000001,
                ent_feature,
                1, 1613, 61);

            /* GenerateEvent */

            adm_send_event_component_generate_reference(
                ent_feature,
                ent_component_0000000001,
                1, 1615, 61);
        }

        rel_feature_includes_component_0000000001 = rel_feature_includes_component_0000000001->next;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_object_not_found
            )
        )) {

        /* GenerateEvent */

        adm_send_event_feature_complete(
            ent_feature,
            ent_feature,
            1, 1623, 53);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_generating_component");
    #endif
}

void adm_state_action_feature_finishing_component_feature(
    adm_ent_feature_typ * ent_feature)
{
    /* Entity Objects */
    adm_ent_feature_typ * ent_feature_0000000001;

    /* Relationship Relations */
    adm_rel_feature_writing_feature_typ * rel_feature_writing_feature_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_finishing_component_feature");
    #endif

    /* Template */

    adm_write_newline();
    adm_template_tab_out(1, 1637, 37);
    adm_write_newline();
    adm_write_str("</Feature>");

    /* Traverse - TraverseSelection */

    adm_object_existent_feature(
        ent_feature,
        1, 1643, 45);

    rel_feature_writing_feature_0000000001 = ent_feature->rel_writing_feature_head;

    if (rel_feature_writing_feature_0000000001 != NULL) {

        ent_feature_0000000001 = rel_feature_writing_feature_0000000001->ent_feature;

        /* Unrelate */

        adm_kill_relation_feature_writing_feature(
            ent_feature,
            rel_feature_writing_feature_0000000001,
            1, 1646, 49);

        /* GenerateEvent */

        adm_send_event_feature_done(
            ent_feature,
            ent_feature_0000000001,
            1, 1648, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_feature_finishing_component_feature");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */