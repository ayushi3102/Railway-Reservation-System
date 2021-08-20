#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include "ctype.h"
#include<string.h>
int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=0;i<=80;i++)
    {
        printf("-");
    }
    printf("\nSelect an option");
    printf("\n1-View Trains");
    printf("\n2-Book Ticket");
    printf("\n3-View Ticket");
    printf("\n4-Search Ticket No");
    printf("\n5-View All Bookings");
    printf("\n6-View Train Bookings");
    printf("\n7-Cancel Ticket");
    printf("\n8-Cancel Train");
    printf("\n9-Quit");
    printf("\n\nEnter choice ");
    scanf("%d",&choice);
    return choice;
}

void add_trains()
{
    Train alltrains[4]={{"123","BPL","GWA",2100,1500},
    {"321","BPL","DEL",3500,2240},
    {"456","HBJ","AGR",1560,1135},
    {"654","HBJ","MUM",4500,3360}};
    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\alltrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("e:\\C 2020\\myprojectfiles\\alltrains.dat","wb");

        printf("File created and saved\n");

    }
    else
fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("");
        //File already present;
    fclose(fp);

}
void view_trains()
{
    int i;
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
    for(i=0;i<=80;i++)
    {
        printf("-");
    }
    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\alltrains.dat","rb");
   Train tr;
   while(fread(&tr,sizeof(tr),1,fp)==1)
   {

       printf("\n%s\t\t%s\t\%s\t\%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);

   }
   printf("\n\n");
   fclose(fp);
}
int check_train_no(char *trainno)
{
        FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\alltrains.dat","rb");
   Train tr;
   while(fread(&tr,sizeof(tr),1,fp)==1)
   {

       if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }

   }
   fclose(fp);
   return 0;
}
int check_mob_no(char *mobno)
{   int i;
    if(strlen(mobno)!=10)
        return 0;
    for(i=0;mobno[i]!='\0';i++)
    {
        if(mobno[i]<48 || mobno[i]>57)
            return 0;
    }
    return 1;
}
Passenger * get_passenger_details()
{
    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(100,1);
    printf("Press 0 to exit");
    static Passenger psn;
    textcolor(YELLOW);
    gotoxy(1,1);
    printf("Enter Passenger Name: ");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
         gotoxy(1,30);
         textcolor(RED);
         printf("\t\t\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Reservation cancelled");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
    }

    int valid;
    printf("Enter gender(M/F): ");

    do{
         valid=1;
         fflush(stdin);
         scanf("%c",&psn.gender);
         if(psn.gender=='0')
       {
         textcolor(RED);
         gotoxy(1,30);
         printf("\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Reservation cancelled");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
       }
         if(psn.gender!='M'&&psn.gender!='F')
         {

            textcolor(RED);
            gotoxy(1,30);
            printf("Error! Gender should be M or F");
            valid=0;
            getch();
            gotoxy(20,2);
            printf(" \b");
            textcolor(YELLOW);
         }
    }while(valid==0);
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter train no: ");
    do{ fflush(stdin);
        scanf("%s",psn.train_no);

        if(strcmp(psn.train_no,"0")==0)
       {
         textcolor(RED);
         gotoxy(1,30);
         printf("\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Reservation cancelled");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
       }valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            textcolor(RED);
            gotoxy(1,30);
            printf("Error! Invalid train no");
            getch();
            gotoxy(16,3);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(16,3);
            textcolor(YELLOW);
        }

    }while(valid==0);
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter travelling class(First AC:F,Second AC:S): ");
    do{
         valid=1;
         fflush(stdin);
         scanf("%c",&psn.p_class);
         if(psn.p_class=='0')
       {
         textcolor(RED);
         gotoxy(1,30);
         printf("\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Reservation cancelled");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
       }
         if(psn.p_class!='F'&&psn.p_class!='S')
         {

            textcolor(RED);
            gotoxy(1,30);
            printf("Error! Class should be S or F");
            valid=0;
            getch();
            gotoxy(49,4);
            printf(" \b");
            textcolor(YELLOW);
         }
    }while(valid==0);
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter address: ");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
         gotoxy(1,30);
         textcolor(RED);
         printf("\t\t\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Reservation cancelled");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,6);
    printf("Enter age: ");

    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
    {
         gotoxy(1,30);
         textcolor(RED);
         printf("\t\t\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Reservation cancelled");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
    }
    if(psn.age<0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,30);
        printf("Error! Age should be positive");
        valid=0;
        getch();
        gotoxy(12,6);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(12,6);
        textcolor(YELLOW);
    }
    }while(valid==0);
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,7);
    printf("Enter mobile number: ");
    do
    {
        fflush(stdin);
        scanf("%s",psn.mob_no);
        if(strcmp(psn.mob_no,"0")==0)
       {
         textcolor(RED);
         gotoxy(1,30);
         printf("\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Reservation cancelled");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
       }
       valid=check_mob_no(psn.mob_no);
       if(valid==0)
       {

           textcolor(RED);
           gotoxy(1,30);
            printf("Error! Invalid moblie no");
            getch();
            gotoxy(21,7);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(21,7);
            textcolor(YELLOW);
       }


    }while(valid==0);
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t");
    clrscr();

   return &psn;

}
int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
        ++count;

    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==2)
    {
        textcolor(LIGHTRED);
        printf("All seats in train no %s in class %c are full",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","ab");
    if(fp==NULL)
    {   textcolor(LIGHTRED);
        printf("Sorry!file cannot be opened");

        return 0;
    }
    fwrite(&p,sizeof(p),1,fp);
        fclose(fp);
        return ticket_no;

}
int accept_ticket_no()
{   int ticket_no,valid;

    printf("Enter ticket no: ");
    do
    {
       scanf("%d",&ticket_no);
    if(ticket_no==0)
    {
         gotoxy(1,30);
         textcolor(RED);
         printf("\t\t\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Cancelling input...");
         getch();
         textcolor(YELLOW);
         clrscr();
         return 0;
    }
    if(ticket_no<0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,30);
        printf("Error!Ticket Number should be positive");
        valid=0;
        getch();
        gotoxy(18,1);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(18,1);
        textcolor(YELLOW);
    }
    else{
        valid=1;
    }
    }while(valid==0);
    return ticket_no;

}
void view_ticket(int ticketno)
{   int i=0;

    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp==NULL)
    {textcolor(LIGHTRED);
       printf("Sorry! File cannot be opened");
       return -1;
    }
   Passenger pr;
   fseek(fp,0,SEEK_SET);
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticketno)
        {

            i=1;
            textcolor(YELLOW);
           printf("Passenger Name: %s\nGender: %c\nTrain no: %s\nClass: %c\nAddress: %s\nAge: %d\nTicket No: %d\nMobile no: %s\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.ticketno,pr.mob_no);
           break;

        }

    }
    if(i==0)
    {
        textcolor(LIGHTRED);
        printf("No details of the ticket found");

    }
    fclose(fp);

}
char * accept_mob_no()
{
   static char mob_no[12];
   char *pos;
   int valid;
   textcolor(LIGHTGREEN);
    gotoxy(100,1);
    printf("Press 0 to exit");
    gotoxy(1,1);
   printf("Enter valid mobile no: ");
   do
   {
       fflush(stdin);
       fgets(mob_no,13,stdin);
       pos=strchr(mob_no,'\n');
       if(pos!=NULL)
        *pos='\0';
       if(strcmp(mob_no,"0")==0)
       {
           gotoxy(1,30);
         textcolor(RED);
         printf("\t\t\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Cancelling input...!");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
       }
        valid=check_mob_no(mob_no);
       if(valid==0)
       {

           textcolor(RED);
           gotoxy(1,30);
            printf("Error! Invalid mobile no");
            getch();
            gotoxy(24,1);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(24,1);
            textcolor(YELLOW);
       }


   }while(valid==0);
   clrscr();
   return mob_no;
}
int * get_ticket_no(char *p_mob_no)
{
  int count=0;
  FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp==NULL)
    {textcolor(LIGHTRED);
       printf("Sorry! File cannot be opened");
       return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(p_mob_no,pr.mob_no)==0)
        {

            ++count;
        }

    }
    if(count==0)
        {
            fclose(fp);
            return NULL;
        }
    int *p=(int *)malloc((count+1)*sizeof(int));
    rewind(fp);
    int i=0;
     while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(p_mob_no,pr.mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }

    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("sorry!No tickers booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\nPress any key to go back to main screen");
        textcolor(YELLOW);
        getch();
        return;
    }
    printf("Following are tickets booked for the mobile number %s",pmob_no);
    int i;
    printf("\n\nTICKET NUMBERS");
    printf("\n--------------------------------------------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n %d",*(pticket_no+i));
    textcolor(WHITE);
    printf("\nPress any key to go back to main screen");
    textcolor(YELLOW);
    getch();
    free(pticket_no);
}
char * accept_train_no()
{
    static char trainno[10];
   char *pos;
   int valid;
   textcolor(LIGHTGREEN);
    gotoxy(100,1);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
   printf("Enter valid train no: ");
   do
   {
       fflush(stdin);
       fgets(trainno,10,stdin);
       pos=strchr(trainno,'\n');
       if(pos!=NULL)
        *pos='\0';
       if(strcmp(trainno,"0")==0)
       {
           gotoxy(1,30);
         textcolor(RED);
         printf("\t\t\t\t\t\t\t\t");
         gotoxy(1,30);
         printf("Cancelling input...!");
         getch();
         textcolor(YELLOW);
         clrscr();
         return NULL;
       }
        valid=check_train_no(trainno);
       if(valid==0)
       {

           textcolor(RED);
           gotoxy(1,30);
            printf("Error! Invalid train no");
            getch();
            gotoxy(23,1);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(23,1);
            textcolor(YELLOW);
       }


   }while(valid==0);
   clrscr();
   return trainno;
}
void view_booking(char *trainno)
{
    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp==NULL)
    {textcolor(LIGHTRED);
       printf("Sorry! File cannot be opened");
       return NULL;
    }
    Passenger pr;
    int i=0;
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(i=1;i<=80;i++)
    {
        printf("-");
    }
    printf("\n");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(trainno,pr.train_no)==0)
        {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            i=1;
        }
    }
    if(i!=1)
    {   clrscr();
        textcolor(LIGHTRED);
        printf("No details of bookings of this train no %s found",trainno);
    }
    textcolor(WHITE);
    printf("\nPress any key to go back to main screen");
    textcolor(YELLOW);
    fclose(fp);
    getch();
}
int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp1==NULL)
    {textcolor(LIGHTRED);
       printf("No bookings done yet");
       return -1;
    }
    FILE *fp2=fopen("e:\\C 2020\\myprojectfiles\\temp.dat","wb");
    if(fp2==NULL)
    {textcolor(LIGHTRED);
       printf("Sorry file cannot be created");
       return -1;
    }
    Passenger pr;
    int found=0,result;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno==ticket_no)
         found=1;
        else
            fwrite(&pr,sizeof(pr),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {   remove("e:\\C 2020\\myprojectfiles\\temp.dat");


    }
    else
    {
        result=remove("e:\\C 2020\\myprojectfiles\\allbookings.dat");
        if(result!=0)
            return 2;
        result=rename("e:\\C 2020\\myprojectfiles\\temp.dat","e:\\C 2020\\myprojectfiles\\allbookings.dat");
        if(result!=0)
            return 2;

    }
    return found;
}
void view_all_bookings()
{
    FILE *fp=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp==NULL)
    {textcolor(LIGHTRED);
       printf("Sorry! File cannot be opened");
       return NULL;
    }
    Passenger pr;
    int i=0;
    printf("TRAIN NO\tTICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(i=1;i<=80;i++)
    {
        printf("-");
    }
    printf("\n");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {

            printf("%s\t\t%d\t\t%c\t%s",pr.train_no,pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(50,row);
            printf("\t%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            i=1;
    }
    if(i!=1)
    {   clrscr();
        textcolor(LIGHTRED);
        printf("No bookings found");
    }
    textcolor(WHITE);
    printf("\nPress any key to go back to main screen");
    textcolor(YELLOW);
    fclose(fp);
    getch();
}
int cancel_train(char *trainno)
{

    FILE *fp1=fopen("e:\\C 2020\\myprojectfiles\\allbookings.dat","rb");
    if(fp1==NULL)
    {

        printf("Sorry file cannot be opened\n");
        return -1;
    }
FILE *fp2=fopen("e:\\C 2020\\myprojectfiles\\temp1.dat","wb");
    if(fp2==NULL)
    {textcolor(LIGHTRED);
       printf("Sorry file cannot be created");
       return -1;
    }
    Passenger pr;
     int found=0;
int result;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,trainno)==0)
        {
            found=1;

        }
        else{
            fwrite(&pr,sizeof(pr),1,fp2);
        }

    }
   fclose(fp1);
    fclose(fp2);
    if(found==0)
    {   remove("e:\\C 2020\\myprojectfiles\\temp1.dat");


    }
    else
    {
        result=remove("e:\\C 2020\\myprojectfiles\\allbookings.dat");
        if(result!=0)
            return 2;
        result=rename("e:\\C 2020\\myprojectfiles\\temp1.dat","e:\\C 2020\\myprojectfiles\\allbookings.dat");
        if(result!=0)
            return 2;

    }


return found;

}
