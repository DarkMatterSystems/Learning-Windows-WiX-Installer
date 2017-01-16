
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* Product State Actions */

void adm_state_action_product_generating_product(
    adm_ent_product_typ * ent_product)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_product");
    #endif

    /* Template */

    adm_write_str("<?xml version='1.0' encoding='windows-1252'?>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Learning Edition Installer -->");
    adm_write_newline();
    adm_write_str("<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~ -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>");
    adm_write_newline();
    adm_template_tab_in(1, 58, 37);
    adm_write_newline();
    adm_write_str("<!-- Filename: Matrix-V");
    adm_write_str(ent_product->atb_download_version);
    adm_write_str(".wxs -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Product");
    adm_template_tab_in(1, 58, 37);
    adm_write_newline();
    adm_write_str("Id='");
    adm_write_str(ent_product->atb_id);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Name='");
    adm_write_str(ent_product->atb_name);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("UpgradeCode='");
    adm_write_str(ent_product->atb_upgrade_code);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Language='1033'");
    adm_write_newline();
    adm_write_str("Codepage='1252'");
    adm_write_newline();
    adm_write_str("Version='");
    adm_write_str(ent_product->atb_version);
    adm_write_str("'");
    adm_write_newline();
    adm_write_str("Manufacturer='");
    adm_write_str(ent_product->atb_manufacturer);
    adm_write_str("'>");
    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Prologe -->");
    adm_write_newline();
    adm_write_str("<!-- ~~~~~~~ -->");

    /* GenerateEvent */

    adm_send_event_product_generate(
        ent_product,
        ent_product,
        1, 83, 41);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_product");
    #endif
}

void adm_state_action_product_generating_package(
    adm_ent_product_typ * ent_product)
{
    /* Entity Objects */
    adm_ent_package_typ * ent_package_0000000001;

    /* Relationship Relations */
    adm_rel_product_includes_package_typ * rel_product_includes_package_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_package");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        1, 97, 45);

    rel_product_includes_package_0000000001 = ent_product->rel_includes_package_head;

    ent_package_0000000001 = rel_product_includes_package_0000000001->ent_package;

    /* Relate */

    adm_link_relation_package_writing_product(
        ent_package_0000000001,
        ent_product,
        1, 100, 49);

    /* GenerateEvent */

    adm_send_event_package_generate(
        ent_product,
        ent_package_0000000001,
        1, 102, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_package");
    #endif
}

void adm_state_action_product_generating_property(
    adm_ent_product_typ * ent_product)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_property_typ * ent_property_0000000001;

    /* Relationship Relations */
    adm_rel_product_includes_property_typ * rel_product_includes_property_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_property");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        1, 121, 45);

    rel_product_includes_property_0000000001 = ent_product->rel_includes_property_head;

    while (rel_product_includes_property_0000000001 != NULL) {

        ent_property_0000000001 = rel_product_includes_property_0000000001->ent_property;

        /* CaseSelection */

        if (
            (
                (
                    pdt_object_not_found
                )
                &&
                !(
                    ent_property_0000000001->atb_processed
                )
            )) {

            /* Assignment - Set */

            pdt_object_not_found = FALSE;

            /* Assignment - Set */

            ent_property_0000000001->atb_processed = TRUE;

            /* Relate */

            adm_link_relation_property_writing_product(
                ent_property_0000000001,
                ent_product,
                1, 136, 61);

            /* GenerateEvent */

            adm_send_event_property_generate(
                ent_product,
                ent_property_0000000001,
                1, 138, 61);
        }

        rel_product_includes_property_0000000001 = rel_product_includes_property_0000000001->next;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_object_not_found
            )
        )) {

        /* GenerateEvent */

        adm_send_event_product_complete(
            ent_product,
            ent_product,
            1, 146, 53);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_property");
    #endif
}

void adm_state_action_product_generating_icon(
    adm_ent_product_typ * ent_product)
{
    /* Process Data */
    adm_bln_flag_typ pdt_object_not_found;

    /* Entity Objects */
    adm_ent_icon_typ * ent_icon_0000000001;

    /* Relationship Relations */
    adm_rel_product_includes_icon_typ * rel_product_includes_icon_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_icon");
    #endif

    /* Assignment - Set */

    pdt_object_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        1, 165, 45);

    rel_product_includes_icon_0000000001 = ent_product->rel_includes_icon_head;

    while (rel_product_includes_icon_0000000001 != NULL) {

        ent_icon_0000000001 = rel_product_includes_icon_0000000001->ent_icon;

        /* CaseSelection */

        if (
            (
                (
                    pdt_object_not_found
                )
                &&
                !(
                    ent_icon_0000000001->atb_processed
                )
            )) {

            /* Assignment - Set */

            pdt_object_not_found = FALSE;

            /* Assignment - Set */

            ent_icon_0000000001->atb_processed = TRUE;

            /* Relate */

            adm_link_relation_icon_writing_product(
                ent_icon_0000000001,
                ent_product,
                1, 180, 61);

            /* GenerateEvent */

            adm_send_event_icon_generate(
                ent_product,
                ent_icon_0000000001,
                1, 182, 61);
        }

        rel_product_includes_icon_0000000001 = rel_product_includes_icon_0000000001->next;
    }

    /* CaseSelection */

    if (
        (
            (
                pdt_object_not_found
            )
        )) {

        /* GenerateEvent */

        adm_send_event_product_complete(
            ent_product,
            ent_product,
            1, 190, 53);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_icon");
    #endif
}

void adm_state_action_product_generating_directory(
    adm_ent_product_typ * ent_product)
{
    /* Entity Objects */
    adm_ent_directory_typ * ent_directory_0000000001;

    /* Relationship Relations */
    adm_rel_product_includes_directory_typ * rel_product_includes_directory_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_directory");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        1, 204, 45);

    rel_product_includes_directory_0000000001 = ent_product->rel_includes_directory_head;

    ent_directory_0000000001 = rel_product_includes_directory_0000000001->ent_directory;

    /* Relate */

    adm_link_relation_directory_writing_product(
        ent_directory_0000000001,
        ent_product,
        1, 207, 49);

    /* GenerateEvent */

    adm_send_event_directory_generate(
        ent_product,
        ent_directory_0000000001,
        1, 209, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_directory");
    #endif
}

void adm_state_action_product_generating_feature(
    adm_ent_product_typ * ent_product)
{
    /* Entity Objects */
    adm_ent_feature_typ * ent_feature_0000000001;

    /* Relationship Relations */
    adm_rel_product_includes_feature_typ * rel_product_includes_feature_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_feature");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_product(
        ent_product,
        1, 223, 45);

    rel_product_includes_feature_0000000001 = ent_product->rel_includes_feature_head;

    ent_feature_0000000001 = rel_product_includes_feature_0000000001->ent_feature;

    /* Relate */

    adm_link_relation_feature_writing_product(
        ent_feature_0000000001,
        ent_product,
        1, 226, 49);

    /* GenerateEvent */

    adm_send_event_feature_generate(
        ent_product,
        ent_feature_0000000001,
        1, 228, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_feature");
    #endif
}

void adm_state_action_product_generating_miscellaneous(
    adm_ent_product_typ * ent_product)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_miscellaneous");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Miscellaneous -->");
    adm_write_newline();
    adm_write_str("<!-- ~~~~~~~~~~~~~ -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<Media");
    adm_write_newline();
    adm_write_str("    Id='1'");
    adm_write_newline();
    adm_write_str("    Cabinet='Sample.cab'");
    adm_write_newline();
    adm_write_str("    EmbedCab='yes'");
    adm_write_newline();
    adm_write_str("    DiskPrompt='CD-ROM #1'/>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<CustomAction");
    adm_write_newline();
    adm_write_str("    Id='AssignTargetDir'");
    adm_write_newline();
    adm_write_str("    Property='TARGETDIR'");
    adm_write_newline();
    adm_write_str("    Value='C:\\'");
    adm_write_newline();
    adm_write_str("    Execute='firstSequence'/>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<InstallUISequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("    <Custom");
    adm_write_newline();
    adm_write_str("        Action='AssignTargetDir'");
    adm_write_newline();
    adm_write_str("        Before='CostInitialize'>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("        TARGETDIR=\"\"");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("     </Custom>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("</InstallUISequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<InstallExecuteSequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("    <Custom");
    adm_write_newline();
    adm_write_str("        Action='AssignTargetDir'");
    adm_write_newline();
    adm_write_str("        Before='CostInitialize'>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("        TARGETDIR=\"\"");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("     </Custom>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("</InstallExecuteSequence>");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<UIRef Id='WixUI_Minimal'/>");
    adm_write_newline();
    adm_write_str("<UIRef Id='WixUI_ErrorProgressText'/>");
    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Replace Standard License and Installer Icons -->");
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<WixVariable Id='WixUILicenseRtf' Value='Source\\Licence.rtf'/>");
    adm_write_newline();
    adm_write_str("<WixVariable Id='WixUIDialogBmp'  Value='Source\\Icons\\UIDialog.bmp'/>");
    adm_write_newline();
    adm_write_str("<WixVariable Id='WixUIBannerBmp'  Value='Source\\Icons\\UIBanner.bmp'/>");

    /* GenerateEvent */

    adm_send_event_product_complete(
        ent_product,
        ent_product,
        1, 292, 41);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_generating_miscellaneous");
    #endif
}

void adm_state_action_product_idle(
    adm_ent_product_typ * ent_product)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_idle");
    #endif

    /* Template */

    adm_write_newline();
    adm_template_tab_out(1, 304, 37);
    adm_write_newline();
    adm_write_str("</Product>");
    adm_write_newline();
    adm_template_tab_out(1, 304, 37);
    adm_write_newline();
    adm_write_str("</Wix>");
    adm_write_newline();
    adm_write_newline();
    adm_write_newline();
    adm_write_str("<!-- Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. -->");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_product_idle");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */