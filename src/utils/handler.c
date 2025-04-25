#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "display.h"
#include "input.h"
#include "miscellaneous.h"

void _hndl_create()
{
    dsp_print("creating contact...");

    if (cont_list_full())
    {
        dsp_print_error("Contact creation impossible - contact limit exceeded.");
        return;
    }

    Contact new_contact;
    input_get_contact(&new_contact);
    dsp_contact_print_preview(&new_contact);

confirm:
    int choice = input_get_yn_choice();
    switch (choice)
    {
    case OPTION_YES:
        cont_add(&new_contact);
        dsp_print_success("Created new contact.");
        break;
    case OPTION_NO:
        dsp_print("Contact creation aborted.");
        break;
    case OPTION_INVALID:
        goto confirm;
        break;
    }
}

void _hndl_update()
{
    if (cont_list_empty())
    {
        dsp_print_error("Can't update a contact cause you have none.");
        return;
    }
    
    dsp_print("updating contact...");

    int input_id = input_get_id();

    if (input_id == OPTION_INVALID)
    {
        dsp_print_error("Bad input format.");
        return;
    }

    Contact *contact = cont_get_contact_with_id(input_id);
    if (contact == NULL)
    {
        dsp_print_error("Contact ID doesn't exist.");
        return;
    }

    dsp_contact_print(contact);

    Contact updated_contact;
    input_get_contact(&updated_contact);
    updated_contact.id = input_id;
    dsp_contact_print_preview(&updated_contact);

confirm:
    int choice = input_get_yn_choice();
    switch (choice)
    {
    case OPTION_YES:
        cont_update(input_id, &updated_contact);
        dsp_print_success("Contact updated.");
        break;
    case OPTION_NO:
        dsp_print("Updating contact aborted.");
        break;
    case OPTION_INVALID:
        goto confirm;
        break;
    }
}

void _hndl_delete()
{
    if (cont_list_empty())
    {
        dsp_print_error("Can't delete a contact cause you have none.");
        return;
    }

    dsp_print("deleting contact...");

    int input = input_get_id();

    if (input == OPTION_INVALID)
    {
        dsp_print_error("Bad input format.");
        return;
    }

    Contact *contact = cont_get_contact_with_id(input);
    if (contact == NULL)
    {
        dsp_print_error("Contact ID doesn't exist.");
        return;
    }

    dsp_contact_print(contact);

confirm:
    int choice = input_get_yn_choice();
    switch (choice)
    {
    case OPTION_YES:
        cont_delete(contact->id);
        dsp_print_success("Contact deleted.");
        break;
    case OPTION_NO:
        dsp_print("Deleting contact aborted.");
        break;
    case OPTION_INVALID:
        goto confirm;
        break;
    }
}

void _hndl_view_all()
{
    dsp_contact_print_all();
}

void _hndl_view_details()
{
    if (cont_list_empty())
    {
        dsp_print_error("Can't show contact details. You don't even have a contact.");
        return;
    }
    
    dsp_print("viewing contact details...");

    int input = input_get_id();

    if (input == OPTION_INVALID)
    {
        dsp_print_error("Bad input format.");
        return;
    }

    Contact *contact = cont_get_contact_with_id(input);
    if (contact == NULL)
    {
        dsp_print_error("Contact ID doesn't exist.");
        return;
    }

    dsp_contact_print(contact);
}

void _hndl_exit()
{
    dsp_print("exitting...");
    exit(0);
}

void _hndl_invalid()
{
    dsp_print_error("Invalid input. Type 'h' for help.");
}

void _hndl_help()
{
    dsp_print_menu();
}

void hndl_menu_choice(int choice)
{
    switch (choice)
    {
    case OPTION_CREATE:
        _hndl_create();
        break;
    case OPTION_UPDATE:
        _hndl_update();
        break;
    case OPTION_DELETE:
        _hndl_delete();
        break;
    case OPTION_VIEW_ALL:
        _hndl_view_all();
        break;
    case OPTION_VIEW_DETAILS:
        _hndl_view_details();
        break;
    case OPTION_EXIT:
        _hndl_exit();
        break;
    case OPTION_HELP:
        _hndl_help();
        break;
    case OPTION_INVALID:
        _hndl_invalid();
        break;
    }
}
