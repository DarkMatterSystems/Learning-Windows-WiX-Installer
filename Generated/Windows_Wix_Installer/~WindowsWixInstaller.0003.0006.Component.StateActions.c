
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* Component State Actions */

void adm_state_action_component_generating(
    adm_ent_component_typ * ent_component)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Component");
    adm_template_tab_in(1, 702, 37);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_component->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Guid='");
    adm_write_str(ent_component->atb_guid);
    adm_write_str("'>");

    /* CaseSelection */

    if (
        (
            (
                strcmp(ent_component->atb_condition, "")
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_newline();
        adm_write_str("<Condition>");
        adm_template_tab_in(1, 714, 49);
        adm_write_newline();
        adm_write_newline();
        adm_write_str(ent_component->atb_condition);
        adm_template_tab_out(1, 714, 49);
        adm_write_newline();
        adm_write_newline();
        adm_write_str("</Condition>");
    }

    /* GenerateEvent */

    adm_send_event_component_generate(
        ent_component,
        ent_component,
        1, 724, 41);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating");
    #endif
}

void adm_state_action_component_generating_file(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_file_typ * ent_file_0000000001;

    /* Relationship Relations */
    adm_rel_component_includes_file_typ * rel_component_includes_file_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_file");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 738, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_component_includes_file_0000000001 = ent_component->rel_includes_file_head;

    if (rel_component_includes_file_0000000001 != NULL) {

        ent_file_0000000001 = rel_component_includes_file_0000000001->ent_file;

        traverse_not_found_0000000002 = FALSE;

        /* Relate */

        adm_link_relation_file_writing_component(
            ent_file_0000000001,
            ent_component,
            1, 741, 49);

        /* GenerateEvent */

        adm_send_event_file_generate(
            ent_component,
            ent_file_0000000001,
            1, 743, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_component,
            ent_component,
            1, 746, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_file");
    #endif
}

void adm_state_action_component_generating_uninstall_shortcut(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut_0000000001;

    /* Relationship Relations */
    adm_rel_component_includes_uninstall_shortcut_typ * rel_component_includes_uninstall_shortcut_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_uninstall_shortcut");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 760, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_component_includes_uninstall_shortcut_0000000001 = ent_component->rel_includes_uninstall_shortcut_head;

    if (rel_component_includes_uninstall_shortcut_0000000001 != NULL) {

        ent_uninstall_shortcut_0000000001 = rel_component_includes_uninstall_shortcut_0000000001->ent_uninstall_shortcut;

        traverse_not_found_0000000002 = FALSE;

        /* Relate */

        adm_link_relation_uninstall_shortcut_writing_component(
            ent_uninstall_shortcut_0000000001,
            ent_component,
            1, 763, 49);

        /* GenerateEvent */

        adm_send_event_uninstall_shortcut_generate(
            ent_component,
            ent_uninstall_shortcut_0000000001,
            1, 765, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_component,
            ent_component,
            1, 768, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_uninstall_shortcut");
    #endif
}

void adm_state_action_component_generating_create_folder(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_create_folder_typ * ent_create_folder_0000000001;

    /* Relationship Relations */
    adm_rel_component_includes_create_folder_typ * rel_component_includes_create_folder_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_create_folder");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 782, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_component_includes_create_folder_0000000001 = ent_component->rel_includes_create_folder_head;

    if (rel_component_includes_create_folder_0000000001 != NULL) {

        ent_create_folder_0000000001 = rel_component_includes_create_folder_0000000001->ent_create_folder;

        traverse_not_found_0000000002 = FALSE;

        /* Relate */

        adm_link_relation_create_folder_writing_component(
            ent_create_folder_0000000001,
            ent_component,
            1, 785, 49);

        /* GenerateEvent */

        adm_send_event_create_folder_generate(
            ent_component,
            ent_create_folder_0000000001,
            1, 787, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_component,
            ent_component,
            1, 790, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_create_folder");
    #endif
}

void adm_state_action_component_generating_remove_folder(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_remove_folder_typ * ent_remove_folder_0000000001;

    /* Relationship Relations */
    adm_rel_component_includes_remove_folder_typ * rel_component_includes_remove_folder_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_remove_folder");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 804, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_component_includes_remove_folder_0000000001 = ent_component->rel_includes_remove_folder_head;

    if (rel_component_includes_remove_folder_0000000001 != NULL) {

        ent_remove_folder_0000000001 = rel_component_includes_remove_folder_0000000001->ent_remove_folder;

        traverse_not_found_0000000002 = FALSE;

        /* Relate */

        adm_link_relation_remove_folder_writing_component(
            ent_remove_folder_0000000001,
            ent_component,
            1, 807, 49);

        /* GenerateEvent */

        adm_send_event_remove_folder_generate(
            ent_component,
            ent_remove_folder_0000000001,
            1, 809, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_component,
            ent_component,
            1, 812, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_remove_folder");
    #endif
}

void adm_state_action_component_generating_environment(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_environment_typ * ent_environment_0000000001;

    /* Relationship Relations */
    adm_rel_component_includes_environment_typ * rel_component_includes_environment_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_environment");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 826, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_component_includes_environment_0000000001 = ent_component->rel_includes_environment_head;

    if (rel_component_includes_environment_0000000001 != NULL) {

        ent_environment_0000000001 = rel_component_includes_environment_0000000001->ent_environment;

        traverse_not_found_0000000002 = FALSE;

        /* Relate */

        adm_link_relation_environment_writing_component(
            ent_environment_0000000001,
            ent_component,
            1, 829, 49);

        /* GenerateEvent */

        adm_send_event_environment_generate(
            ent_component,
            ent_environment_0000000001,
            1, 831, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_component,
            ent_component,
            1, 834, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_environment");
    #endif
}

void adm_state_action_component_generating_registry_key(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_registry_key_typ * ent_registry_key_0000000001;

    /* Relationship Relations */
    adm_rel_component_includes_registry_key_typ * rel_component_includes_registry_key_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_registry_key");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 848, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_component_includes_registry_key_0000000001 = ent_component->rel_includes_registry_key_head;

    if (rel_component_includes_registry_key_0000000001 != NULL) {

        ent_registry_key_0000000001 = rel_component_includes_registry_key_0000000001->ent_registry_key;

        traverse_not_found_0000000002 = FALSE;

        /* Relate */

        adm_link_relation_registry_key_writing_component(
            ent_registry_key_0000000001,
            ent_component,
            1, 851, 49);

        /* GenerateEvent */

        adm_send_event_registry_key_generate(
            ent_component,
            ent_registry_key_0000000001,
            1, 853, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_component,
            ent_component,
            1, 856, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_registry_key");
    #endif
}

void adm_state_action_component_generating_registry_value(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_registry_value_typ * ent_registry_value_0000000001;

    /* Relationship Relations */
    adm_rel_component_includes_registry_value_typ * rel_component_includes_registry_value_0000000001;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_registry_value");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 870, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_component_includes_registry_value_0000000001 = ent_component->rel_includes_registry_value_head;

    if (rel_component_includes_registry_value_0000000001 != NULL) {

        ent_registry_value_0000000001 = rel_component_includes_registry_value_0000000001->ent_registry_value;

        traverse_not_found_0000000002 = FALSE;

        /* Relate */

        adm_link_relation_registry_value_writing_component(
            ent_registry_value_0000000001,
            ent_component,
            1, 873, 49);

        /* GenerateEvent */

        adm_send_event_registry_value_generate(
            ent_component,
            ent_registry_value_0000000001,
            1, 875, 49);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* GenerateEvent */

        adm_send_event_component_complete(
            ent_component,
            ent_component,
            1, 878, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_registry_value");
    #endif
}

void adm_state_action_component_idle(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_directory_typ * ent_directory_0000000001;

    /* Relationship Relations */
    adm_rel_component_writing_directory_typ * rel_component_writing_directory_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_idle");
    #endif

    /* Template */

    adm_write_newline();
    adm_template_tab_out(1, 890, 37);
    adm_write_newline();
    adm_write_str("</Component>");

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 896, 45);

    rel_component_writing_directory_0000000001 = ent_component->rel_writing_directory_head;

    if (rel_component_writing_directory_0000000001 != NULL) {

        ent_directory_0000000001 = rel_component_writing_directory_0000000001->ent_directory;

        /* Unrelate */

        adm_kill_relation_component_writing_directory(
            ent_component,
            rel_component_writing_directory_0000000001,
            1, 899, 49);

        /* GenerateEvent */

        adm_send_event_directory_done(
            ent_component,
            ent_directory_0000000001,
            1, 901, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_idle");
    #endif
}

void adm_state_action_component_generating_reference(
    adm_ent_component_typ * ent_component)
{
    /* Entity Objects */
    adm_ent_feature_typ * ent_feature_0000000001;

    /* Relationship Relations */
    adm_rel_component_writing_feature_typ * rel_component_writing_feature_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_reference");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("<ComponentRef Id='");
    adm_write_str(ent_component->atb_id);
    adm_write_str("'/>");

    /* Traverse - TraverseSelection */

    adm_object_existent_component(
        ent_component,
        1, 917, 45);

    rel_component_writing_feature_0000000001 = ent_component->rel_writing_feature_head;

    if (rel_component_writing_feature_0000000001 != NULL) {

        ent_feature_0000000001 = rel_component_writing_feature_0000000001->ent_feature;

        /* Unrelate */

        adm_kill_relation_component_writing_feature(
            ent_component,
            rel_component_writing_feature_0000000001,
            1, 920, 49);

        /* GenerateEvent */

        adm_send_event_feature_done(
            ent_component,
            ent_feature_0000000001,
            1, 922, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_component_generating_reference");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */