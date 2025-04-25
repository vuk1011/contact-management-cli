#ifndef INPUT_H_
#define INPUT_H_

#include "contact.h"

enum menu_option
{
    OPTION_CREATE,
    OPTION_UPDATE,
    OPTION_DELETE,
    OPTION_VIEW_ALL,
    OPTION_VIEW_DETAILS,
    OPTION_EXIT,
    OPTION_HELP,
    OPTION_YES,
    OPTION_NO,
    OPTION_INVALID,
};

int input_get_menu_choice();
void input_get_contact(Contact *contact);
int input_get_yn_choice();
int input_get_id();

#endif
