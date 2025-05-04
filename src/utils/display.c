#include <stdio.h>

#include "display.h"
#include "miscellaneous.h"

#define _ANSI_CLEAR_SCREEN "\033[2J"
#define _ANSI_CURSOR_TOP_LEFT "\033[H"

#define _ANSI_RESET_STYLE "\033[0m"

#define _ANSI_FOREGROUND_RED "\033[31m"
#define _ANSI_FOREGROUND_GREEN "\033[32m"
#define _ANSI_FOREGROUND_YELLOW "\033[33m"
#define _ANSI_FOREGROUND_BLACK_BACKGROUND_WHITE "\033[30;47m"

#define _START_MSG "Welcome to Contact Management!"

#define _MENU_OPTION_1 "(1) Create"
#define _MENU_OPTION_2 "(2) Update"
#define _MENU_OPTION_3 "(3) Delete"
#define _MENU_OPTION_4 "(4) View All Contacts"
#define _MENU_OPTION_5 "(5) View Contact Details"
#define _MENU_OPTION_6 "(6) Exit"
#define _MENU_OPTION_7 "(h) Help - show menu again"

#define _INPUT_PROMPT ">>"

#define _HORIZONTAL_LINE "----------------"

void _dsp_clear_screen()
{
    printf("%s%s", _ANSI_CLEAR_SCREEN, _ANSI_CURSOR_TOP_LEFT);
}

void _dsp_print_start_msg()
{
    printf("%s\n", _START_MSG);
}

void dsp_print_menu()
{
    printf("\nChoose an action by typing a digit:\n");
    printf("\t%s\n", _MENU_OPTION_1);
    printf("\t%s\n", _MENU_OPTION_2);
    printf("\t%s\n", _MENU_OPTION_3);
    printf("\t%s\n", _MENU_OPTION_4);
    printf("\t%s\n", _MENU_OPTION_5);
    printf("\t%s\n", _MENU_OPTION_6);
    printf("\t%s\n", _MENU_OPTION_7);
    printf("\n");
}

void dsp_start()
{
    _dsp_clear_screen();
    _dsp_print_start_msg();
    dsp_print_menu();
}

void dsp_print_error(const char *message)
{
    printf("%s%s%s\n", _ANSI_FOREGROUND_RED, message, _ANSI_RESET_STYLE);
    misc_error_check();
}

void dsp_print(const char *message)
{
    printf("%s\n", message);
}

void dsp_print_highlighted(const char *message)
{
    printf("%s%s%s\n", _ANSI_FOREGROUND_BLACK_BACKGROUND_WHITE, message, _ANSI_RESET_STYLE);
}

void dsp_print_success(const char *message)
{
    printf("%s%s%s\n", _ANSI_FOREGROUND_GREEN, message, _ANSI_RESET_STYLE);
}

void dsp_prompt_for_input()
{
    printf("%s ", _INPUT_PROMPT);
}

void dsp_prompt_for_input_msg(const char *message)
{
    printf("%s\n", message);
    dsp_prompt_for_input();
}

void _dsp_contact_print(Contact *contact)
{
    printf("%sFirst name: %s\n", _ANSI_FOREGROUND_YELLOW, contact->first_name);
    printf("Last name:  %s\n", contact->last_name);
    printf("Phone:      %s\n", contact->phone);
    printf("E-mail:     %s\n", contact->email);
    printf("Birthday:   %s%s\n", contact->birthday, _ANSI_RESET_STYLE);
}

void dsp_contact_print_short(Contact *contact)
{
    printf("[%4d]  %-31s %-31s %-15s\n", contact->id, contact->first_name, contact->last_name, contact->phone);
}

void dsp_contact_print(Contact *contact)
{
    printf("\n%sCONTACT [%4d]\n", _ANSI_FOREGROUND_YELLOW, contact->id);
    printf("%s%s\n", _HORIZONTAL_LINE, _ANSI_RESET_STYLE);
    _dsp_contact_print(contact);
    printf("\n");
}

void dsp_contact_print_preview(Contact *contact)
{
    printf("\n%sCONTACT PREVIEW%s\n", _ANSI_FOREGROUND_YELLOW, _ANSI_RESET_STYLE);
    printf("%s%s%s\n", _ANSI_FOREGROUND_YELLOW, _HORIZONTAL_LINE, _ANSI_RESET_STYLE);
    _dsp_contact_print(contact);
    printf("\n");
}

void dsp_contact_print_all()
{
    printf("\n");
    dsp_print_highlighted("CONTACT LIST:");
    printf("%s\n", _HORIZONTAL_LINE);

    if (cont_list_empty())
    {
        printf("(empty)\n");
    }

    for (int i = 0; i < cont_count_get(); i++)
    {
        dsp_contact_print_short(cont_get_contact(i));
        printf("%s\n", _HORIZONTAL_LINE);
    }
    printf("\n");
}
