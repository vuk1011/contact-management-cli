#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "display.h"
#include "input.h"

#define _BUFFER_SIZE 256

char _buffer[_BUFFER_SIZE];

Menu_option input_get_menu_choice()
{
    char input;
    int ret_val;

    dsp_prompt_for_input();
    input = getchar();

    switch (input)
    {
    case '1':
        ret_val = OPTION_CREATE;
        break;
    case '2':
        ret_val = OPTION_UPDATE;
        break;
    case '3':
        ret_val = OPTION_DELETE;
        break;
    case '4':
        ret_val = OPTION_VIEW_ALL;
        break;
    case '5':
        ret_val = OPTION_VIEW_DETAILS;
        break;
    case '6':
        ret_val = OPTION_EXIT;
        break;
    case 'h':
        ret_val = OPTION_HELP;
        break;
    default:
        ret_val = OPTION_INVALID;
        break;
    }

    while ((input = getchar()) != '\n' && input != EOF)
    {
        ret_val = OPTION_INVALID;
    }

    return ret_val;
}

void _input_stdin_clear()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void _input_read_string(int n)
{
    if (n > _BUFFER_SIZE)
        return;
    fgets(_buffer, n, stdin);
    if (strchr(_buffer, '\n') == NULL) // if no newline character is present, stdin should be cleared
    {
        _input_stdin_clear();
    }
    _buffer[strcspn(_buffer, "\n")] = '\0';
}

void input_get_contact(Contact *contact)
{
    // id
    contact->id = cont_count() + 1;

    // first name
    dsp_prompt_for_input_msg("Enter first name (max 31 characters)");
    _input_read_string(32);
    strncpy(contact->first_name, _buffer, 32);

    // last name
    dsp_prompt_for_input_msg("Enter last name (max 31 characters)");
    _input_read_string(32);
    strncpy(contact->last_name, _buffer, 32);

    // phone
    dsp_prompt_for_input_msg("Enter phone (format as '+000999999999')");
    _input_read_string(16);
    strncpy(contact->phone, _buffer, 16);

    // email
    dsp_prompt_for_input_msg("Enter e-mail (max 63 characters)");
    _input_read_string(64);
    strncpy(contact->email, _buffer, 64);

    // birthday
    dsp_prompt_for_input_msg("Enter birthday (format as 'DD-MM-YYYY')");
    _input_read_string(16);
    strncpy(contact->birthday, _buffer, 16);
}

int input_get_yn_choice()
{
    char input;
    int ret_val;

    dsp_prompt_for_input_msg("Confirm action (y/n)");
    input = getchar();

    switch (input)
    {
    case 'y':
        ret_val = OPTION_YES;
        break;
    case 'n':
        ret_val = OPTION_NO;
        break;
    default:
        ret_val = OPTION_INVALID;
        break;
    }

    while ((input = getchar()) != '\n' && input != EOF)
    {
        ret_val = OPTION_INVALID;
    }

    return ret_val;
}

int input_get_id()
{
    dsp_prompt_for_input_msg("Enter contact ID (the number inside [])");
    _input_read_string(5);
    int input = atoi(_buffer);
    return input == 0 ? OPTION_INVALID : input;
}
