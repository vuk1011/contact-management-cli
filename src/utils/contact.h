#ifndef CONTACT_H_
#define CONTACT_H_

#define CONTACT_NAME_LEN 32
#define CONTACT_PHONE_LEN 16
#define CONTACT_EMAIL_LEN 64
#define CONTACT_BIRTHDAY_LEN 16

typedef struct
{
    int id;
    char first_name[CONTACT_NAME_LEN];
    char last_name[CONTACT_NAME_LEN];
    char phone[CONTACT_PHONE_LEN];
    char email[CONTACT_EMAIL_LEN];
    char birthday[CONTACT_BIRTHDAY_LEN];
} Contact;

#define CONTACTS_MAX 1024

int cont_count();
int cont_list_full();
int cont_list_empty();
void cont_add(Contact *contact);
void cont_delete(int id);
void cont_update(int id, Contact *updated_contact);
Contact *cont_get_contact(int i);
Contact *cont_get_contact_with_id(int id);

#endif
