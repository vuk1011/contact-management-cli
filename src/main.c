#include "utils/display.h"
#include "utils/handler.h"
#include "utils/input.h"
#include "utils/storage.h"

int main(int argc, char const *argv[])
{
    /*
    TODO:
    - use github for todo's
    - search functionality
    - persistency
    */
   
    st_load_contacts();
    dsp_start();

    int choice = -1;
    while (choice != OPTION_EXIT)
    {
        choice = input_get_menu_choice();
        hndl_menu_choice(choice);
    }

    st_store_contacts();

    return 0;
}
