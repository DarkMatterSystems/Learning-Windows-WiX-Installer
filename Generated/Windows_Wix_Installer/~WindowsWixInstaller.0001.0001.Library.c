
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* System Library */

/* Allocate Memory */

void * adm_allocate_memory(
    adm_base_integer_typ amount)
{
    void * memory;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_allocate_memory");
    #endif

    memory = malloc(amount);

    if (memory == NULL) {

        adm_error_report(
            ADM_ERROR_OUT_OF_MEMORY,
            0, 0, 0, NULL, null, NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_allocate_memory");
    #endif

    return (memory);
}


/* Dellocate Memory */

void adm_deallocate_memory(
    void * memory)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_deallocate_memory");
    #endif

    free(memory);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_deallocate_memory");
    #endif
}


/* Open Stream File */

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    errno_t file_error;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_open_stream_file");
    #endif

    if (adm_stream.streaming) {

        adm_close_stream_file(
            error_file,
            error_line,
            error_rank);
    }

    file_error = fopen_s(&adm_stream.channel, adm_stream.pathname, "w");

    if (file_error) {

        adm_error_report(
            ADM_ERROR_CREATE_STREAM_FILE_FAILED,
            error_file, error_line, error_rank,
            adm_stream.pathname,
            null, NULL, NULL);

    } else {

        adm_stream.active    = TRUE;
        adm_stream.streaming = TRUE;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_open_stream_file");
    #endif
}


/* Close Stream File */

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_close_stream_file");
    #endif

    if (adm_stream.streaming) {

        if (fclose(adm_stream.channel) == EOF) {

            adm_error_report(
                ADM_ERROR_CLOSE_STREAM_FILE_FAILED,
                error_file, error_line, error_rank,
                adm_stream.pathname,
                null, NULL, NULL);

        } else {

            adm_stream.streaming = FALSE;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_close_stream_file");
    #endif
}


/* Write Integer */

void adm_write_int(
    adm_base_integer_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_int");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%d", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%d", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_int");
    #endif
}


/* Write Boolean */

void adm_write_bln(
    adm_base_boolean_typ value)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_bln");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%s", adm_indent.tab, adm_boolean[value]) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%s", adm_indent.tab, adm_boolean[value]);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_bln");
    #endif
}


/* Write Fixed */

void adm_write_fxd(
    adm_base_fixed_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_fxd");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%f", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%f", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_fxd");
    #endif
}


/* Write Float */

void adm_write_flt(
    adm_base_float_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_flt");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%E", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%E", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_flt");
    #endif
}


/* Write String */

void adm_write_str(
    adm_base_string_typ * string)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_str");
    #endif

    if (adm_stream.active) {

        if (!NULL_STR(string)) {

            if (adm_stream.streaming) {

                if (fprintf(adm_stream.channel, "%s%s", adm_indent.tab, string) < 0) {

                    adm_error_report(
                        ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                        0, 0, 0,
                        adm_stream.pathname,
                        null, NULL, NULL);
                }

            } else {

                printf("%s%s", adm_indent.tab, string);
            }

            INIT_STR(adm_indent.tab);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_str");
    #endif
}


/* Write Newline */

void adm_write_newline(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_newline");
    #endif

    if (adm_stream.active) {

        INIT_STR(adm_indent.tab);

        adm_write_str(NEWLINE);

        memset(adm_indent.tab, ' ', adm_indent.width);

        adm_indent.tab[adm_indent.width] = '\0';
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_newline");
    #endif
}


/* Set Template Tab In */

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_in");
    #endif

    if (adm_stream.active) {

        adm_indent.width += ADM_INDENT_TAB_TEMPLATE_INDENT_SIZE;

        if (adm_indent.width > ADM_INDENT_TEMPLATE_MAXIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_TEMPLATE_MAXIMUM_TAB_INDENT_EXCEEDED,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_in");
    #endif
}


/* Set Template Tab Out */

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_out");
    #endif

    if (adm_stream.active) {

        adm_indent.width -= ADM_INDENT_TAB_TEMPLATE_INDENT_SIZE;

        if (adm_indent.width < ADM_INDENT_TEMPLATE_MINIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_TEMPLATE_MINIMUM_TAB_INDENT_OFFPAGE,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_out");
    #endif
}


/* Set Display Tab In */

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_in");
    #endif

    if (adm_stream.active) {

        adm_indent.width += ADM_INDENT_TAB_DISPLAY_INDENT_SIZE;

        if (adm_indent.width > ADM_INDENT_DISPLAY_MAXIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_DISPLAY_MAXIMUM_TAB_INDENT_EXCEEDED,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_in");
    #endif
}


/* Set Display Tab Out */

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_out");
    #endif

    if (adm_stream.active) {

        adm_indent.width -= ADM_INDENT_TAB_DISPLAY_INDENT_SIZE;

        if (adm_indent.width < ADM_INDENT_DISPLAY_MINIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_DISPLAY_MINIMUM_TAB_INDENT_OFFPAGE,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_out");
    #endif
}


/* String - Convert Upper Case */

void adm_convert_string_upper_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_upper_case");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        target_string[index] = toupper(source_string[index]);

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_upper_case");
    #endif
}


/* String - Convert Lower Case */

void adm_convert_string_lower_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_lower_case");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        target_string[index] = tolower(source_string[index]);

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_lower_case");
    #endif
}


/* String - Convert Sentence Case */

void adm_convert_string_sentence_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_sentence_case");
    #endif

    adm_convert_string_lower_case(
        source_string,
        target_string);

    target_string[0] = toupper(target_string[0]);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_sentence_case");
    #endif
}


/* Convert Capital Case */

void adm_convert_string_capital_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ capitalise;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_capital_case");
    #endif

    capitalise = TRUE;

    index = 0;

    while (source_string[index] != '\0') {

        if (
            source_string[index] == ' ' ||
            source_string[index] == '_') {

            capitalise = TRUE;

            target_string[index] = source_string[index];

        } else {

            if (capitalise) {

                capitalise = FALSE;

                target_string[index] = toupper(source_string[index]);

            } else {

                target_string[index] = tolower(source_string[index]);
            }
        }

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_capital_case");
    #endif
}


/* String - Convert Remove Spaces */

void adm_convert_string_remove_spaces(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ source_index;
    adm_base_integer_typ target_index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_remove_spaces");
    #endif

    source_index = 0;
    target_index = 0;

    while (source_string[source_index] != '\0') {

        if (source_string[source_index] != ' ') {

            target_string[target_index] = source_string[source_index];

            ++target_index;
        }

        ++source_index;
    }

    target_string[target_index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_remove_spaces");
    #endif
}


/* String - Convert Underlines */

void adm_convert_string_convert_underlines(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_convert_underlines");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        if (source_string[index] == '_') {

            target_string[index] = ' ';

        } else {

            target_string[index] = source_string[index];
        }

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_convert_underlines");
    #endif
}


/* Integrity Check */

void adm_integrity_check(
    void)
{
    adm_ent_product_typ * ent_product;
    adm_ent_icon_typ * ent_icon;
    adm_ent_package_typ * ent_package;
    adm_ent_property_typ * ent_property;
    adm_ent_directory_typ * ent_directory;
    adm_ent_component_typ * ent_component;
    adm_ent_file_typ * ent_file;
    adm_ent_file_shortcut_typ * ent_file_shortcut;
    adm_ent_uninstall_shortcut_typ * ent_uninstall_shortcut;
    adm_ent_create_folder_typ * ent_create_folder;
    adm_ent_remove_folder_typ * ent_remove_folder;
    adm_ent_environment_typ * ent_environment;
    adm_ent_registry_key_typ * ent_registry_key;
    adm_ent_registry_value_typ * ent_registry_value;
    adm_ent_feature_typ * ent_feature;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_integrity_check");
    #endif

    ent_product = adm_entity_system.ent_product.live_list_head;

    while (ent_product != NULL) {

        if (ent_product->rel_includes_icon_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 37, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Icon");
        }

        if (ent_product->rel_includes_package_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 38, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Package");
        }

        if (
            ent_product->rel_includes_package_head != 
            ent_product->rel_includes_package_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 38, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Package");
        }

        if (ent_product->rel_includes_property_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 39, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Property");
        }

        if (ent_product->rel_includes_directory_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 40, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Directory");
        }

        if (
            ent_product->rel_includes_directory_head != 
            ent_product->rel_includes_directory_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 40, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Directory");
        }

        if (ent_product->rel_includes_feature_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 41, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Feature");
        }

        if (
            ent_product->rel_includes_feature_head != 
            ent_product->rel_includes_feature_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 41, 29,
                "Product",
                ent_product->identity,
                "Includes",
                "Feature");
        }

        ent_product = ent_product->next;
    }

    ent_icon = adm_entity_system.ent_icon.live_list_head;

    while (ent_icon != NULL) {

        if (
            ent_icon->rel_writing_product_head != 
            ent_icon->rel_writing_product_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 329, 29,
                "Icon",
                ent_icon->identity,
                "Writing",
                "Product");
        }

        ent_icon = ent_icon->next;
    }

    ent_package = adm_entity_system.ent_package.live_list_head;

    while (ent_package != NULL) {

        if (
            ent_package->rel_writing_product_head != 
            ent_package->rel_writing_product_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 363, 29,
                "Package",
                ent_package->identity,
                "Writing",
                "Product");
        }

        ent_package = ent_package->next;
    }

    ent_property = adm_entity_system.ent_property.live_list_head;

    while (ent_property != NULL) {

        if (
            ent_property->rel_writing_product_head != 
            ent_property->rel_writing_product_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 404, 29,
                "Property",
                ent_property->identity,
                "Writing",
                "Product");
        }

        ent_property = ent_property->next;
    }

    ent_directory = adm_entity_system.ent_directory.live_list_head;

    while (ent_directory != NULL) {

        if (
            ent_directory->rel_writing_product_head != 
            ent_directory->rel_writing_product_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 441, 29,
                "Directory",
                ent_directory->identity,
                "Writing",
                "Product");
        }

        if (
            ent_directory->rel_writing_directory_head != 
            ent_directory->rel_writing_directory_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 442, 29,
                "Directory",
                ent_directory->identity,
                "Writing",
                "Directory");
        }

        ent_directory = ent_directory->next;
    }

    ent_component = adm_entity_system.ent_component.live_list_head;

    while (ent_component != NULL) {

        if (
            ent_component->rel_includes_file_head != 
            ent_component->rel_includes_file_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 677, 29,
                "Component",
                ent_component->identity,
                "Includes",
                "File");
        }

        if (
            ent_component->rel_includes_uninstall_shortcut_head != 
            ent_component->rel_includes_uninstall_shortcut_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 678, 29,
                "Component",
                ent_component->identity,
                "Includes",
                "Uninstall_Shortcut");
        }

        if (
            ent_component->rel_includes_create_folder_head != 
            ent_component->rel_includes_create_folder_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 679, 29,
                "Component",
                ent_component->identity,
                "Includes",
                "Create_Folder");
        }

        if (
            ent_component->rel_includes_remove_folder_head != 
            ent_component->rel_includes_remove_folder_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 680, 29,
                "Component",
                ent_component->identity,
                "Includes",
                "Remove_Folder");
        }

        if (
            ent_component->rel_includes_environment_head != 
            ent_component->rel_includes_environment_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 681, 29,
                "Component",
                ent_component->identity,
                "Includes",
                "Environment");
        }

        if (
            ent_component->rel_includes_registry_key_head != 
            ent_component->rel_includes_registry_key_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 682, 29,
                "Component",
                ent_component->identity,
                "Includes",
                "Registry_Key");
        }

        if (
            ent_component->rel_includes_registry_value_head != 
            ent_component->rel_includes_registry_value_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 683, 29,
                "Component",
                ent_component->identity,
                "Includes",
                "Registry_Value");
        }

        if (
            ent_component->rel_writing_directory_head != 
            ent_component->rel_writing_directory_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 684, 29,
                "Component",
                ent_component->identity,
                "Writing",
                "Directory");
        }

        if (
            ent_component->rel_writing_feature_head != 
            ent_component->rel_writing_feature_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 685, 29,
                "Component",
                ent_component->identity,
                "Writing",
                "Feature");
        }

        ent_component = ent_component->next;
    }

    ent_file = adm_entity_system.ent_file.live_list_head;

    while (ent_file != NULL) {

        if (
            ent_file->rel_writing_component_head != 
            ent_file->rel_writing_component_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 938, 29,
                "File",
                ent_file->identity,
                "Writing",
                "Component");
        }

        ent_file = ent_file->next;
    }

    ent_file_shortcut = adm_entity_system.ent_file_shortcut.live_list_head;

    while (ent_file_shortcut != NULL) {

        if (
            ent_file_shortcut->rel_writing_file_head != 
            ent_file_shortcut->rel_writing_file_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1077, 29,
                "File_Shortcut",
                ent_file_shortcut->identity,
                "Writing",
                "File");
        }

        if (ent_file_shortcut->rel_specialisation_shortcut_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 1078, 29,
                "File_Shortcut",
                ent_file_shortcut->identity,
                "Specialisation",
                "Shortcut");
        }

        if (
            ent_file_shortcut->rel_specialisation_shortcut_head != 
            ent_file_shortcut->rel_specialisation_shortcut_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1078, 29,
                "File_Shortcut",
                ent_file_shortcut->identity,
                "Specialisation",
                "Shortcut");
        }

        ent_file_shortcut = ent_file_shortcut->next;
    }

    ent_uninstall_shortcut = adm_entity_system.ent_uninstall_shortcut.live_list_head;

    while (ent_uninstall_shortcut != NULL) {

        if (
            ent_uninstall_shortcut->rel_writing_component_head != 
            ent_uninstall_shortcut->rel_writing_component_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1121, 29,
                "Uninstall_Shortcut",
                ent_uninstall_shortcut->identity,
                "Writing",
                "Component");
        }

        if (ent_uninstall_shortcut->rel_specialisation_shortcut_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 1122, 29,
                "Uninstall_Shortcut",
                ent_uninstall_shortcut->identity,
                "Specialisation",
                "Shortcut");
        }

        if (
            ent_uninstall_shortcut->rel_specialisation_shortcut_head != 
            ent_uninstall_shortcut->rel_specialisation_shortcut_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1122, 29,
                "Uninstall_Shortcut",
                ent_uninstall_shortcut->identity,
                "Specialisation",
                "Shortcut");
        }

        ent_uninstall_shortcut = ent_uninstall_shortcut->next;
    }

    ent_create_folder = adm_entity_system.ent_create_folder.live_list_head;

    while (ent_create_folder != NULL) {

        if (
            ent_create_folder->rel_writing_component_head != 
            ent_create_folder->rel_writing_component_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1159, 29,
                "Create_Folder",
                ent_create_folder->identity,
                "Writing",
                "Component");
        }

        ent_create_folder = ent_create_folder->next;
    }

    ent_remove_folder = adm_entity_system.ent_remove_folder.live_list_head;

    while (ent_remove_folder != NULL) {

        if (
            ent_remove_folder->rel_writing_component_head != 
            ent_remove_folder->rel_writing_component_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1188, 29,
                "Remove_Folder",
                ent_remove_folder->identity,
                "Writing",
                "Component");
        }

        ent_remove_folder = ent_remove_folder->next;
    }

    ent_environment = adm_entity_system.ent_environment.live_list_head;

    while (ent_environment != NULL) {

        if (
            ent_environment->rel_writing_component_head != 
            ent_environment->rel_writing_component_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1222, 29,
                "Environment",
                ent_environment->identity,
                "Writing",
                "Component");
        }

        ent_environment = ent_environment->next;
    }

    ent_registry_key = adm_entity_system.ent_registry_key.live_list_head;

    while (ent_registry_key != NULL) {

        if (ent_registry_key->rel_includes_registry_value_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 1260, 29,
                "Registry_Key",
                ent_registry_key->identity,
                "Includes",
                "Registry_Value");
        }

        if (
            ent_registry_key->rel_includes_registry_value_head != 
            ent_registry_key->rel_includes_registry_value_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1260, 29,
                "Registry_Key",
                ent_registry_key->identity,
                "Includes",
                "Registry_Value");
        }

        if (
            ent_registry_key->rel_writing_component_head != 
            ent_registry_key->rel_writing_component_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1261, 29,
                "Registry_Key",
                ent_registry_key->identity,
                "Writing",
                "Component");
        }

        ent_registry_key = ent_registry_key->next;
    }

    ent_registry_value = adm_entity_system.ent_registry_value.live_list_head;

    while (ent_registry_value != NULL) {

        if (
            ent_registry_value->rel_writing_component_head != 
            ent_registry_value->rel_writing_component_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1338, 29,
                "Registry_Value",
                ent_registry_value->identity,
                "Writing",
                "Component");
        }

        if (
            ent_registry_value->rel_writing_registry_key_head != 
            ent_registry_value->rel_writing_registry_key_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1339, 29,
                "Registry_Value",
                ent_registry_value->identity,
                "Writing",
                "Registry_Key");
        }

        ent_registry_value = ent_registry_value->next;
    }

    ent_feature = adm_entity_system.ent_feature.live_list_head;

    while (ent_feature != NULL) {

        if (
            ent_feature->rel_writing_product_head != 
            ent_feature->rel_writing_product_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1406, 29,
                "Feature",
                ent_feature->identity,
                "Writing",
                "Product");
        }

        if (
            ent_feature->rel_writing_feature_head != 
            ent_feature->rel_writing_feature_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 1407, 29,
                "Feature",
                ent_feature->identity,
                "Writing",
                "Feature");
        }

        ent_feature = ent_feature->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_integrity_check");
    #endif
}


#if ADM_PROBE

/* Probe Enter */

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name)
{
    adm_base_string_typ probe_message [ADM_PROBE_MESSAGE_SIZE];

    if (
        !adm_probe_display.none &&
        (adm_probe_display.all                                                        ||
        (adm_probe_display.main_program   && group == ADM_PROBE_GROUP_MAIN_PROGRAM)   ||
        (adm_probe_display.initialisation && group == ADM_PROBE_GROUP_INITIALISATION) ||
        (adm_probe_display.scheduler      && group == ADM_PROBE_GROUP_SCHEDULER)      ||
        (adm_probe_display.dispatcher     && group == ADM_PROBE_GROUP_DISPATCHER)     ||
        (adm_probe_display.state_action   && group == ADM_PROBE_GROUP_STATE_ACTION)   ||
        (adm_probe_display.data_access    && group == ADM_PROBE_GROUP_DATA_ACCESS)    ||
        (adm_probe_display.event_sender   && group == ADM_PROBE_GROUP_EVENT_SENDER)   ||
        (adm_probe_display.enumeration    && group == ADM_PROBE_GROUP_ENUMERATION)    ||
        (adm_probe_display.library        && group == ADM_PROBE_GROUP_LIBRARY)        ||
        (adm_probe_display.identifier     && group == ADM_PROBE_GROUP_IDENTIFIER)     ||
        (adm_probe_display.error          && group == ADM_PROBE_GROUP_ERROR)          ||
        (adm_probe_display.simulator      && group == ADM_PROBE_GROUP_SIMULATOR))) {

        INIT_STR(probe_message);

        adm_add_spaces(probe_message, adm_probe_display.level);

        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, "ENTER: ");
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, procedure_name);
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, NEWLINE);

        printf(probe_message);

        fprintf(adm_file_channel, probe_message);

        adm_probe_display.level += ADM_PROBE_INDENT;
    }
}


/* Probe Leave */

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name)
{
    adm_base_string_typ probe_message [ADM_PROBE_MESSAGE_SIZE];

    if (
        !adm_probe_display.none &&
        (adm_probe_display.all                                                        ||
        (adm_probe_display.main_program   && group == ADM_PROBE_GROUP_MAIN_PROGRAM)   ||
        (adm_probe_display.initialisation && group == ADM_PROBE_GROUP_INITIALISATION) ||
        (adm_probe_display.scheduler      && group == ADM_PROBE_GROUP_SCHEDULER)      ||
        (adm_probe_display.dispatcher     && group == ADM_PROBE_GROUP_DISPATCHER)     ||
        (adm_probe_display.state_action   && group == ADM_PROBE_GROUP_STATE_ACTION)   ||
        (adm_probe_display.data_access    && group == ADM_PROBE_GROUP_DATA_ACCESS)    ||
        (adm_probe_display.event_sender   && group == ADM_PROBE_GROUP_EVENT_SENDER)   ||
        (adm_probe_display.enumeration    && group == ADM_PROBE_GROUP_ENUMERATION)    ||
        (adm_probe_display.library        && group == ADM_PROBE_GROUP_LIBRARY)        ||
        (adm_probe_display.identifier     && group == ADM_PROBE_GROUP_IDENTIFIER)     ||
        (adm_probe_display.error          && group == ADM_PROBE_GROUP_ERROR)          ||
        (adm_probe_display.simulator      && group == ADM_PROBE_GROUP_SIMULATOR))) {

        adm_probe_display.level -= ADM_PROBE_INDENT;

        INIT_STR(probe_message);

        adm_add_spaces(probe_message, adm_probe_display.level);

        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, "LEAVE: ");
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, procedure_name);
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, NEWLINE);

        printf(probe_message);

        fprintf(adm_file_channel, probe_message);
    }
}


/* Add Spaces */

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number)
{
    adm_base_integer_typ index;

    for (index=0; index<space_number; ++index) {

        strcat_s(space_string, ADM_PROBE_MESSAGE_SIZE, " ");
    }
}

#endif

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */