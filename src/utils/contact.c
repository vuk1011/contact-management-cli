#include <stdlib.h>
#include <string.h>

#include "contact.h"

Contact _contacts[CONTACTS_MAX];
int _count = 0;

int cont_count()
{
    return _count;
}

int cont_list_full()
{
    return _count == CONTACTS_MAX;
}

int cont_list_empty()
{
    return _count == 0;
}

void cont_add(Contact *contact)
{
    _contacts[_count++] = *contact;
}

void cont_delete(int id)
{
    for (int i = id - 1; i < _count - 1; i++)
    {
        _contacts[i] = _contacts[i + 1];
        _contacts[i].id--;
    }

    _count--;
}

void cont_update(int id, Contact *updated_contact)
{
    strcpy(_contacts[id - 1].first_name, updated_contact->first_name);
    strcpy(_contacts[id - 1].last_name, updated_contact->last_name);
    strcpy(_contacts[id - 1].phone, updated_contact->phone);
    strcpy(_contacts[id - 1].email, updated_contact->email);
    strcpy(_contacts[id - 1].birthday, updated_contact->birthday);
}

Contact *cont_get_contact(int i)
{
    return &_contacts[i];
}

Contact *cont_get_contact_with_id(int id)
{
    if (id < 1 || id > _count)
    {
        return NULL;
    }

    return &_contacts[id - 1];
}
