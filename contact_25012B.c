#include <stdio.h>
#include "contact.h"
#include<string.h>
/* Function definitions */
void init_intitalization(struct Address_book *addressbook)
{
}
int create_contact(struct Address_book *addressbook)
{
        int i;
        for(i=0;i<3;i++)
        {
            printf("\nEnter the name: ");
            scanf(" %31[^\n]",addressbook->contact_details[addressbook->contact_count].Name);
            clear_buffer();
            int n=name_validation(addressbook->contact_details[addressbook->contact_count].Name);
           if(n!=1)
             break;
        }
        if(i>=3)
        {
        printf("\nToo many attempts\n");
        return 0;
        }
     int ch;
        int j;
        for(j=0;j<3;j++)
        {
        printf("Enter ph.no : ");
        scanf(" %11[^\n]",addressbook->contact_details[addressbook->contact_count].Mobile_number);
        clear_buffer();
    
        int m=mobile_validation(addressbook->contact_details[addressbook->contact_count].Mobile_number,addressbook);
        if(m!=1)
            break;
        }
        if(j>=3)
        {
            printf("\nToo many attempts\n");
            return 0;
        }
     int k;
     for( k=0;k<3;k++)
     {
       printf("Enter email Id : ");
       scanf(" %34[^\n]",addressbook->contact_details[addressbook->contact_count].Mail_ID);
        clear_buffer();
       int e= email_validation_with_uniq(addressbook->contact_details[addressbook->contact_count].Mail_ID,addressbook);
        if(e!=1)
       {
         break;
       }
     }
    if(k==3)
    {
        printf("Too many attempts\n");
        return 0;
    }
     addressbook->contact_count+=1;
     printf("contact added successfully\n");
    return 0;
}
void list_contacts(struct Address_book *addressbook)
{
    printf("..........................................................................\n");
    printf("S.NO\tName\t\t\tMobile Number\tEmail_ID\n");
    printf("..........................................................................\n");
    for(int i=0;i<addressbook->contact_count;i++)
    {
        printf(" %d.\t%s\t\t\t%s\t%s\n",i+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }
    printf("..........................................................................\n");
}
int search_contacts(struct Address_book *addressbook)
{
    while(1)
    {
    printf("\n1.Search by Name\n2.Search by Mobile Number\n3.Search by Email_Id\n4.Exit\n");
    printf("Enter the Option : ");
    int n;
    scanf("%d",&n);
     clear_buffer();
       switch(n)
      {
        case 1:
        {
        int a=search_by_name(addressbook);
        if(a>=0)
        {
            return a;
        }
          break;
        }
        case 2:
        {  
        int n= search_by_number(addressbook);
            if(n>=0)
            {   printf("..........................................................................\n");
                printf("S.NO\tName\t\tMobile Number\tEmail_ID\n");
                printf("..........................................................................\n");
                printf(" 1\t%s\t\t%s\t%s\n",addressbook->contact_details[n].Name,addressbook->contact_details[n].Mobile_number,addressbook->contact_details[n].Mail_ID);
                printf("..........................................................................\n");
                return n;
            }
        break;
        }
        case 3:
        {   
           int e=search_by_mail(addressbook);
            if(e>=0)
            {
                printf("..........................................................................\n");
                printf("S.NO\tName\t\t\tMobile Number\tEmail_ID\n");
                printf("..........................................................................\n");
                printf(" 1\t%s\t\t\t%s\t%s\n",addressbook->contact_details[e].Name,addressbook->contact_details[e].Mobile_number,addressbook->contact_details[e].Mail_ID);
                printf("..........................................................................\n");
                return e;
            }   
           break;
        }
        case 4:
        {
        return 0;
    
        }
        default:
        {
        printf("Invalid option\n");
        break;
        }
     }
    }
 // return 0;
}
int edit_contact(struct Address_book *addressbook)
{  
    int a= searching_for_edit_contact(addressbook);
   if(a>=0)
   {
    while(1)
    {
        printf("\nWhich field do you want to edit\n");
        printf("1.Name\n2.Mobile Number\n3.Email\n4.Exit\n");
        int n;
        char ch;
        printf("Enter the option: ");
        scanf("%d",&n);
         clear_buffer();
        switch(n)
        {
            case 1:
            {
                int b=edit_name( a, addressbook);
                if(b==1)
                {
                printf("\nName updated successfully\n");
                }
                break;
            }
            case 2:
            {
                int b=edit_number(a,addressbook);
                if(b==1)
                {
                 printf("\nNumber updated successfully\n");
                }
                break;
            }
            case 3:
            {
                int b=edit_mail(a,addressbook);
                if(b==1)
                {
                printf("\nMail updated successfully\n");
                }
                break;
            }
            case 4:
            {
                return 0;
            }
            default:
            {
                printf("Invalid Option\n");
                break;
            }
        }
    }
   }
    return 0;
}
int delete_contact(struct Address_book *addressbook)
{
    int a=searching_for_edit_contact(addressbook);
    if(a>=0)
    {
        printf("\nDo you want to delete? Press 1-YES and 2-NO\n");
        int n;
        printf("Enter the option : ");
        scanf("%d",&n);
         clear_buffer();
        if(n==1)
        {
            int b=delete_contact_data(a,addressbook);
            if(b==1)
            {
                printf("\nContact Deleted Successfully!\n");
                printf("\n");
                return 0;
            }
        }
        else if(n==2)
        {
            return 0;
        }
        else
        {
            printf("Invalid option\n ");
        }
    }
    return 0;
}
 int name_validation(char * name)
  {
        if(name[0]>='0' && name[0]<='9')
        {
            printf("Name should not be start with digits\n");
            return 1;
        }
        else
        {
            return 0;
        }
  }
  int mobile_validation(char * number ,struct Address_book *addressbook)
  {
    if(strlen(number)<10 || strlen(number)>10)
    {
        printf("The Number should have 10 digits\n");
        return 1;
    }
    if(number[0]>='0' && number[0]<='5')
    {
        printf("Number should be start between 6 to 9\n");
        return 1;
    }
        int i=0;
        while(number[i])
        {
            if(number[i]>='A'&&number[i]<='~' ||number[i]>='\0' && number[i]<='/')
            {
                printf("The Number should have only Digits\n");
                return 1;
            }
            i++;
        }
        int j=0;
        while(j<addressbook->contact_count)
        {
        if(!strcmp(addressbook->contact_details[j].Mobile_number,number))
        {
             printf("Please give Uniq Number\n");
             return 1;
        }
        j++;
       }
       if(j>=addressbook->contact_count)
       {
        return 0;
       }
  }
int search_mobile(char * number)
{
    if(strlen(number)<10 || strlen(number)>10)
    {
        printf("The number should have 10 digits\n");
        return 1;
    }
    if(number[0]>='0' && number[0]<='5')
    {
        printf("Number should be start between 6 to 9\n");
        return 1;
    }
    else
    {
        int i=0;
        while(number[i])
        {
            if(number[i]>='A'&&number[i]<='~' ||number[i]>='\0' && number[i]<='/')
            {
                printf("The should have only numbers\n");
                return 1;
            }
            i++;
         }
    }
        return 0;
}
int email_endswith(char* email)
{
    int a=strlen(email);
    char *str=".com";
    int b=strlen(str);
    if(a<b)
    {
        return 1;
    }
    return strcmp(email+a-b,str)==0;
}
int email_validation(char * email)
{
    if(email[0]>='0' && email[0]<='9')
    {
        printf("Email should not start with digits\n");
        return 1;
    }
    if(email[0]>='!' && email[0]<='/')
    {
    printf("Email should not start with special characters\n");
    return 1;
    }
   int a=email_endswith(email);
      if(!a)
    {
        printf("Email must be end with .com\n");
        return 1;
    }
    int i=0;
    while(email[i])
    {
        if((email[i]<'a' || email[i]>'z') && email[i]!='@' && email[i]!='.')
        { 
            printf("Email must be in lowercase without spaces and special characters\n");
            return 1;
        }
        i++;
    }
    int k=0;
    while(email[k])
    {
        if(email[k]=='@')
        {
            if(email[k+1]=='.' || email[k+1]>='0' && email[k+1]<='9')
            {
            printf("Email should not contain @ and .  side by side and numbers\n");
            return 1;
            }
        }
        k++;
    }
    int count=0,c=0;
    char *ch=strchr(email,'@');
    if(ch==NULL)
    {
        printf("Email must have @ character\n");
        return 1;
    }
    while(ch!=NULL)
    {
        count++;
        ch=strchr(ch+1,'@');
    }
    if(count>1)
    {
        printf("@ character must be one time in mail\n");
        return 1;
    }
    char *res=strstr(email,".com");
    if(res==NULL)
    {
        printf("Email must be end with .com\n");
        return 1;
    }
    while(res!=NULL)
    {
        c++;
        res=strstr(res+1,".com");
    }
    if(c>1)
    {
        printf("Email should be one .com string\n");
        return 1;
    }
    return 0; 
}
int email_validation_with_uniq(char * email,struct Address_book*addressbook)
{
    if(email[0]>='0' && email[0]<='9')
    {
        printf("Email should not start with digits\n");
        return 1;
    }
    if(email[0]>='!' && email[0]<='/')
    {
    printf("Email should not start with special characters\n");
    return 1;
    }
   int a=email_endswith(email);
      if(!a)
      {
        printf("Email must be end with .com\n");
        return 1;
      }

    int i=0;
    while(email[i])
    {
        if((email[i]<'a' || email[i]>'z') && email[i]!='@' && email[i]!='.')
        { 
            printf("Email must be in lowercase without spaces and special characters\n");
            return 1;
        }
        i++;
    }
    int k=0;
    while(email[k])
    {
        if(email[k]=='@')
        {
            if(email[k+1]=='.' || email[k+1]>='0' && email[k+1]<='9')
            {
            printf("Email should not contain @ and .  side by side and numbers\n");
            return 1;
            }
        }
        k++;
    }
    int count=0,c=0;
    char *ch=strchr(email,'@');
    if(ch==NULL)
    {
        printf("Email must have @ character\n");
        return 1;
    }
    while(ch!=NULL)
    {
        count++;
        ch=strchr(ch+1,'@');
    }
    if(count>1)
    {
        printf("@ character must be one time in mail\n");
        return 1;
    }
    char *res=strstr(email,".com");
    if(res==NULL)
    {
        printf("Email must be end with .com\n");
        return 1;
    }
    while(res!=NULL)
    {
        c++;
        res=strstr(res+1,".com");
    }
    if(c>1)
    {
        printf("Email should be one .com string\n");
        return 1;
    }
    int m=0;
           while(m<addressbook->contact_count)
           {
            if(! strcmp(email,addressbook->contact_details[m].Mail_ID))
            {
                printf("The Email already exist.Please give another email\n");
                return 1;
            }
            m++;
           }
    return 0;  
}
int search_by_name(struct Address_book*addressbook)
{
     char str[32];
        int i;
        for(i=0;i<3;i++)
        {   
            printf("\nEnter the Name :");
            scanf(" %31[^\n]",str);
             clear_buffer();
            int n= name_validation(str);
             if(n!=1)
             {
             break;
             }
        }
            if(i>=3)
            {
                printf("Too many attempts\n");
                i=10;
                return -1;
            }
            if(i!=10)
            {
            int j=0;
            int count=0;
           while(j<addressbook->contact_count)
           {
            if(!( strcmp(addressbook->contact_details[j].Name,str)))
            {    
                count+=1;
            }
            j++;
           }
           if(count==0)
           {
            printf("CONTACT NOT FOUND\n");
             printf("Do you want to search again? if not press 4 to Exit\n ");
            return -1;
           }
           if(count==1)
           {
            int l=0;
            while(l<addressbook->contact_count)
           {
            if(!( strcmp(addressbook->contact_details[l].Name,str)))
            {  
                 printf("\nCONTACT FOUND\n ");
            printf("..........................................................................\n");
            printf("S.NO\tName\t\tMobile Number\tEmail_ID\n"); 
            printf("..........................................................................\n");  
               
            printf(" 1\t%s\t\t%s\t%s\n",addressbook->contact_details[l].Name,addressbook->contact_details[l].Mobile_number,addressbook->contact_details[l].Mail_ID);
            printf("..........................................................................\n");  
                return l;
            }
            l++;
           }
           }
           if(count>1)
           {
            printf("\nCONTACT FOUND\n ");
            printf("..........................................................................\n");
            printf("S.NO\tName\t\tMobile_Number\tEmail_ID\n");
            printf("..........................................................................\n");
            int l=0;
            int i=0;
            while(l<addressbook->contact_count)
           {
            if(!( strcmp(addressbook->contact_details[l].Name,str)))
            {  
                printf(" %d\t%s\t\t%s\t%s\n",++i,addressbook->contact_details[l].Name,addressbook->contact_details[l].Mobile_number,addressbook->contact_details[l].Mail_ID);   
            }
            l++;
           }
           printf("..........................................................................\n");  
           printf("\nDo you want to search again? if not press 4 to exit\n");
           return -1;
           }
      }
      return 0;    
}
int search_by_same_name(struct Address_book*addressbook)
{
     char str[32];
        int i;
        for(i=0;i<3;i++)
        {   
            printf("\nEnter the Name :");
            scanf(" %31[^\n]",str);
             clear_buffer();
            int n= name_validation(str);
             if(n!=1)
             {
             break;
             }
        }
            if(i>=3)
            {
                printf("Too many attempts\n");
                i=10;
                return -1;
            }
            if(i!=10)
            {
            int j=0;
            int count=0;
           while(j<addressbook->contact_count)
           {
            if(!( strcmp(addressbook->contact_details[j].Name,str)))
            {    
                count+=1;
            }
            j++;
           }
           if(count==0)
           {
            printf("CONTACT NOT FOUND\n");
             printf("Do you want to search again? if not press 4 to Exit\n ");
            return -1;
           }
           if(count==1)
           {
            int l=0;
            while(l<addressbook->contact_count)
           {
            if(!( strcmp(addressbook->contact_details[l].Name,str)))
            {    
                printf("\nCONTACT FOUND\n ");
                 printf("..........................................................................\n");  
            printf("\nS.NO\tName\t\tMobile Number\tEmail_ID\n"); 
             printf("..........................................................................\n");  
            printf(" 1\t%s\t\t%s\t%s\n",addressbook->contact_details[l].Name,addressbook->contact_details[l].Mobile_number,addressbook->contact_details[l].Mail_ID);
             printf("..........................................................................\n");  
            printf("\n");
                return l;
            }
            l++;
           }
           }
           if(count>1)
           {
            printf("\nCONTACT FOUND\n ");
             printf("..........................................................................\n");  
            printf("Contact No.\tName\t\tMobile_Number\tEmail_ID\n");
             printf("..........................................................................\n");  
            int l=0;
            while(l<addressbook->contact_count)
           {
            if(!( strcmp(addressbook->contact_details[l].Name,str)))
            {  
                printf(" %d\t\t%s\t\t%s\t%s\n",l,addressbook->contact_details[l].Name,addressbook->contact_details[l].Mobile_number,addressbook->contact_details[l].Mail_ID);   
            }
            l++;
           }
            printf("..........................................................................\n");  
           int n;
           printf("\nWhich Contact No. do you want to edit or delete\n");
           printf("Enter Index No :");
           scanf("%d",&n);
           clear_buffer();
           if(n>=0 && n<addressbook->contact_count)
           {
            return n;
           }
           else
           {
            printf("Invalid Entry\n");
            return -1;
           }
          }
      }
      return 0;    
}
int search_by_number(struct Address_book*addressbook )
{
   char ch;
     int j;
           char number[12];
        for(j=0;j<3;j++)
        {
        printf("Enter ph.no : ");
         scanf(" %11[^\n]",number);
         clear_buffer();
        int m=search_mobile(number);
        if(m==0)
        {
            break;
        }
        }
        if(j>=3)
        {
            printf("Too many attempts\n");
            j=10;
            return -1;
        }
        if(j!=10)
        {
            int i=0;
            while(i<addressbook->contact_count)
            {
                if(! strcmp(addressbook->contact_details[i].Mobile_number,number))
                {
                    printf("\nCONTACT FOUND\n");
                    return i;
                }
                i++;
            }
            if(i>=addressbook->contact_count)
            {
            printf("\nCONTACT NOT FOUND\n");
             printf("Do you want to search again? if not press 4 to Exit\n ");
            return -1;
            }
        }
     return 0;
}
int search_by_mail(struct Address_book*addressbook)
{
    char email[35];
          int k;
          for( k=0;k<3;k++)
          {
              printf("Enter email Id : ");
              scanf(" %34[^\n]",email);
              clear_buffer();
              int e=email_validation(email);
              if(!e)
              {
                  break;
              }
           }
           if(k>=3)
           {
              printf("Too many attempts\n");
               k=10;
               return -1;
           }
           if(k!=10)
           {
           int i=0;
           while(i<addressbook->contact_count)
           {
            if(! strcmp(email,addressbook->contact_details[i].Mail_ID))
            {
                printf("\nCONTACT FOUND\n");
                  return i;
            }
            i++;
           }
           if(i>=addressbook->contact_count)
           {
                printf("\nCONTACT NOT FOUND\n");
                printf("Do you want to search again? if not press 4 to Exit\n ");
                return -1;
           }
        }
}
int searching_for_edit_contact(struct Address_book *addressbook)
{
     while(1)
    {
    printf("\n1.Search by Name\n2.Search by Mobile Number\n3.Search by Email_Id\n4.Exit\n");
    printf("Enter the Option : ");
    int n;
    scanf("%d",&n);
    clear_buffer();
       switch(n)
      {
        case 1:
        {
        int a=search_by_same_name(addressbook);
        if(a>=0)
        {
                return a;
        }
          break;
        }
        case 2:
        {  
        int n= search_by_number(addressbook);
            if(n>=0)
            {
                 printf("..........................................................................\n");  
                printf("S.NO\tName\t\tMobile Number\tEmail_ID\n");
                 printf("..........................................................................\n");  
                printf(" 1\t%s\t\t%s\t%s\n",addressbook->contact_details[n].Name,addressbook->contact_details[n].Mobile_number,addressbook->contact_details[n].Mail_ID);
                 printf("..........................................................................\n");  
                printf("\n");
                return n;
            }
        break;
        }
        case 3:
        {   
           int e=search_by_mail(addressbook);
            if(e>=0)
            {
                 printf("..........................................................................\n");  
                printf("S.NO\tName\t\tMobile Number\tEmail_ID\n");
                 printf("..........................................................................\n");  
                printf(" 1\t%s\t\t%s\t%s\n",addressbook->contact_details[e].Name,addressbook->contact_details[e].Mobile_number,addressbook->contact_details[e].Mail_ID);
                 printf("..........................................................................\n");  
                printf("\n");
                return e;
            }   
           break;
        }
        case 4:
        {
        return 0;
    
        }
        default:
        {
        printf("Invalid option\n");
        break;
        }
     }
    }
}
int edit_name(int i, struct Address_book*addressbook)
{
    if (i < 0 || i >= addressbook->contact_count)
    {
        printf("Invalid index for editing name.\n");
        return -1;
    }
    char str[32];
    printf("Enter New Name : ");
    scanf(" %31[^\n]",str);
    clear_buffer();
    int a=name_validation(str);
    if(!a)
    {
        strncpy(addressbook->contact_details[i].Name, str, 31);
        addressbook->contact_details[i].Name[31] = '\0';
        return 1;
    }
    return -1;
}
int edit_number(int i,struct Address_book*addressbook)
{
    if (i < 0 || i >= addressbook->contact_count)
    {
        printf("Invalid index for editing number.\n");
        return -1;
    }
    char number[12];
    char ch;
    printf("Enter New Mobile number: ");
    scanf(" %11[^\n]",number);
    clear_buffer();
    int a=mobile_validation(number,addressbook);
    if(!a)
    {
        strncpy(addressbook->contact_details[i].Mobile_number, number, 11);
        addressbook->contact_details[i].Mobile_number[11] = '\0';
        return 1;
    }
return -1;
}
int edit_mail(int i,struct Address_book*addressbook)
{
    printf("%d",i);
    if (i < 0 || i >= addressbook->contact_count)
    {
        printf("Invalid index for editing email.\n");
        return -1;
    }
    char email[35];
    printf("Enter New Email_Id : ");
    scanf(" %34[^\n]",email);
    clear_buffer();
    int a=email_validation_with_uniq(email,addressbook);
    if(a==0)
    {
        strncpy(addressbook->contact_details[i].Mail_ID, email, 34);
        addressbook->contact_details[i].Mail_ID[34] = '\0';
        return 1;
   }
      return -1;
}
int delete_contact_data(int i,struct Address_book*addressbook)
{
    if (i < 0 || i >= addressbook->contact_count)
    {
        printf("Invalid index for editing number.\n");
        return -1;
    }   
    for(int j=i;j<addressbook->contact_count-1;j++)
    {
    addressbook->contact_details[j]=addressbook->contact_details[j+1]; 
    }
    addressbook->contact_count--;
    return 1;
}
void clear_buffer(void)
{
    char ch;
    while((ch=getchar())!='\n');
}