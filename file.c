#include<stdio.h>
#include"contact.h"
int save_contacts(struct Address_book *addressbook)
{
    FILE *fp=fopen("contacts.csv","w");
    fprintf(fp,"#%d\n",addressbook->contact_count);
        for(int i=0;i<addressbook->contact_count;i++)
        {
            if(feof(fp))
            {
                break;
            }
            fprintf(fp,"%d,%s,%s,%s\n",i+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
        }
        fclose(fp);
    return 0;
}
void load_contacts(struct Address_book *addressbook)
{
        FILE* fp=fopen("contacts.csv","r");
        fscanf(fp,"#%d.\n",&addressbook->contact_count);
        int i;
        int idx;
        for( i=0;i<addressbook->contact_count;i++)
        {
            fscanf(fp,"%d,%31[^,], %11[^,], %34[^\n]",&idx,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
        }
}


