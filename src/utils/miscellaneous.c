#include <stdlib.h>

#include "display.h"

#define _MISC_ERRORS_ALLOWED 3
#define _MISC_ERRORS_EXCEEDED_MSG "Unfortunately, you've exceeded the maximum number of allowed errors. The program is done with you and will shut down."

int _error_count = 0;

void misc_error_check()
{
    if (++_error_count > _MISC_ERRORS_ALLOWED)
    {
        dsp_print(_MISC_ERRORS_EXCEEDED_MSG);
        exit(0);
    }
}
