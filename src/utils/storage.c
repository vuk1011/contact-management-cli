#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "contact.h"
#include "display.h"

char _file_path[64];

void _set_file_path()
{
    const char *home_dir = getenv("HOME");
    strcat(_file_path, home_dir);
    strcat(_file_path, "/.contacts");
}

int _file_exists(const char *path)
{
    return access(path, F_OK) == 0;
}

int _file_create(const char *path)
{
    int fd = open(path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        return 0;
    }
    if (close(fd) == -1)
    {
        return 0;
    }
    return 1;
}

int _read_contacts_from_file(const char *path)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL)
    {
        return 0;
    }

    int count;
    if (fread(&count, sizeof(count), 1, file) != 1)
    {
        fclose(file);
        return 0;
    }
    cont_count_set(count);

    if (fread(contacts, sizeof(Contact), count, file) != count)
    {
        fclose(file);
        return 0;
    }

    if (fclose(file) == EOF)
    {
        return 0;
    }

    return 1;
}

int _write_contacts_to_file(const char *path)
{
    FILE *file = fopen(path, "wb");
    if (file == NULL)
    {
        return 0;
    }

    int count = cont_count_get();
    if (fwrite(&count, sizeof(count), 1, file) != 1)
    {
        fclose(file);
        return 0;
    }

    if (fwrite(contacts, sizeof(Contact), count, file) != count)
    {
        fclose(file);
        return 0;
    }

    if (fclose(file) == EOF)
    {
        return 0;
    }

    return 1;
}

void st_load_contacts()
{
    _set_file_path();

    if (!_file_exists(_file_path))
    {
        if (_file_create(_file_path) == 0)
        {
            dsp_print_error("Something went wrong while creating the storage file.");
            exit(EXIT_FAILURE);
        }
        return;
    }

    if (_read_contacts_from_file(_file_path) == 0)
    {
        dsp_print_error("Something went wrong while reading from the storage file.");
        exit(EXIT_FAILURE);
    }
}

void st_save_contacts()
{
    if (cont_count_get() == 0)
    {
        if (remove(_file_path) != 0)
        {
            dsp_print_error("Something went wrong while removing the contacts file.");
            exit(EXIT_FAILURE);
        }
        return;
    }
    
    if (_write_contacts_to_file(_file_path) == 0)
    {
        dsp_print_error("Something went wrong while storing contacts, changes might not be saved.");
        exit(EXIT_FAILURE);
    }
}
