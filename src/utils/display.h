#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "contact.h"

void dsp_print_menu();
void dsp_start();
void dsp_print_error(const char *message);
void dsp_print(const char *message);
void dsp_print_highlighted(const char *message);
void dsp_print_success(const char *message);
void dsp_prompt_for_input();
void dsp_prompt_for_input_msg(const char *message);
void dsp_contact_print_preview(Contact *contact);
void dsp_contact_print_short(Contact *contact);
void dsp_contact_print(Contact *contact);
void dsp_contact_print_all();

#endif
