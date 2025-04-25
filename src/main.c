#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


#include "utils/contact.h"
#include "utils/display.h"
#include "utils/handler.h"
#include "utils/input.h"

int main(int argc, char const *argv[])
{
    /*
    TODO:
    - search functionality
    - persistency
    - github
    */
   
    dsp_start();

    int choice;
    while (1)
    {
        choice = input_get_menu_choice();
        hndl_menu_choice(choice);
    }

    return 0;
}
