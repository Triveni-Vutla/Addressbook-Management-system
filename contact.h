#ifndef CONTACT_H
#define CONTACT_H

struct Contact_data
{
    char Name[32];
    char Mobile_number[12];
    char Mail_ID[35];
};
struct Address_book
{
    struct Contact_data contact_details[100];
    int contact_count;
};
/* Function declarations */
void init_intitalization(struct Address_book *addressbook);
int create_contact(struct Address_book *);
void list_contacts(struct Address_book *);
int search_contacts(struct Address_book *addressbook);
int edit_contact(struct Address_book *addressbook);
int delete_contact(struct Address_book *addressbook);
int save_contacts(struct Address_book *addressbook);
int name_validation(char *);
int mobile_validation(char * number,struct Address_book * addressbook);
int search_mobile(char * number);
int email_validation_with_uniq(char * email,struct Address_book*addressbook);
int email_validation(char * email);
int email_endswith(char*);
int search_by_name( struct Address_book *addressbook);
int search_by_same_name(struct Address_book*addressbook);
int search_by_number(struct Address_book*addressbook );
int search_by_mail(struct Address_book*addressbook);
int searching_for_edit_contact(struct Address_book *addressbook);
int edit_name(int ,struct Address_book*addressbook);
int edit_number(int,struct Address_book*addressbook);
int edit_mail(int i,struct Address_book*addressbook);
int delete_contact_data(int i,struct Address_book*addressbook);
void load_contacts(struct Address_book *addressbook);
void clear_buffer(void);

#endif // CONTACT_H
// CONTACT_H        