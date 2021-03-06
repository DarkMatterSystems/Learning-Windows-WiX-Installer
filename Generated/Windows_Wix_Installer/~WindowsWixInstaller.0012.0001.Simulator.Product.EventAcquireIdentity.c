
#include "~WindowsWixInstaller.0000.0000.Header.h"


/* Simulator Product Acquire Identity Event */

void adm_sim_acquire_identity_event_product_generate(
    void)
{
    adm_ent_product_typ * ent_product;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_product_generate");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_product = adm_entity_system.ent_product.live_list_head;

    while (
        entity_not_found &&
        ent_product != NULL) {

        if (ent_product->identity == identity) {

            adm_send_event_product_generate(
                NULL,
                ent_product,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_product = ent_product->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_product_generate");
    #endif
}

void adm_sim_acquire_identity_event_product_done(
    void)
{
    adm_ent_product_typ * ent_product;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_product_done");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_product = adm_entity_system.ent_product.live_list_head;

    while (
        entity_not_found &&
        ent_product != NULL) {

        if (ent_product->identity == identity) {

            adm_send_event_product_done(
                NULL,
                ent_product,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_product = ent_product->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_product_done");
    #endif
}

void adm_sim_acquire_identity_event_product_complete(
    void)
{
    adm_ent_product_typ * ent_product;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_product_complete");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_product = adm_entity_system.ent_product.live_list_head;

    while (
        entity_not_found &&
        ent_product != NULL) {

        if (ent_product->identity == identity) {

            adm_send_event_product_complete(
                NULL,
                ent_product,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_product = ent_product->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_product_complete");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */