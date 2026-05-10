#include<stdio.h>
#include<string.h>
FILE *fpter;
void enter(){
    printf("1:Add_new_book \n2:Display_all_books\n3:Search_book\n4:Issue_book\n5:Return_book\n6:Update_book_details\n7:Delete_book_record\n8:Count total books\n");
}
void Add_new_book(){
char t[50],n[50];
int u[10];
char s[3];
printf("\nenter title:");
scanf("%s",t);
printf("\nenter auther name:");
scanf("%s",n);
printf("\nenter number:");
scanf("%s",u);
printf("\nbook is in lib:");
scanf("%s",s);
fprintf(fpter,"%s %s %s %s\n",t,n,u,s);
}
void Display_all_books(){
    fpter=fopen("lib.csv","r");
    char a[500];    
    for(;fgets(a,500,fpter)!=NULL;){
    printf("%s",a);}
    fclose(fpter);
}
void Search_book(){
    char a[500];
    char b[50];
    printf("enter title:");
    scanf("%s",b);
    fpter=fopen("lib.csv","r");
    while(fgets(a,500,fpter)!=NULL){
        if(strstr(a,b)!=NULL){
            // fgets(a,500,fpter);
            
            printf("%s", a);
        }
    }
    fclose(fpter);
}
void Issue_book(){
    char a[500];
    char c[50];
    char b[50];
    printf("enter title:");
    scanf("%s",b);
    fpter=fopen("lib.csv","r+");
    while(fgets(a,500,fpter)!=NULL){
        if(strstr(a,b)!=NULL){
            char *ptr;
            ptr=strstr(a,"yes");
            if (ptr !=NULL){
                fseek(fpter,-4,SEEK_CUR);
                fprintf(fpter,"no ");
                printf("book issued\n");
                break;
            }
            else{
                printf("book already issued\n");
            }  

       }
    }
    fclose(fpter);
}
void Return_book(){
    char a[500];
    char c[50];
    char b[50];
    printf("enter title:");
    scanf("%s",b);
    fpter=fopen("lib.csv","r+");
    while(fgets(a,500,fpter)!=NULL){
        if(strstr(a,b)!=NULL){
            char *ptr;
            ptr=strstr(a,"no ");
            if (ptr !=NULL){
                fseek(fpter,-4,SEEK_CUR);
                fprintf(fpter,"yes");
                printf("book return \n");
                break;
            }
            else{
                printf("book already in lib\n");
            }  

       }
    }
    fclose(fpter);

}
void Delete_book_record(){

    FILE *temp;

    char a[500];
    char b[50];

    printf("enter title:");
    scanf("%s", b);

    fpter = fopen("lib.csv","r");

    temp = fopen("temp.csv","w");

    while(fgets(a,500,fpter)!=NULL){

        if(strstr(a,b)==NULL){

            fprintf(temp,"%s",a);
        }
    }

    fclose(fpter);
    fclose(temp);

    remove("lib.csv");

    rename("temp.csv","lib.csv");

    printf("Book deleted\n");
}
void Count_total_books(){

    char a[500];

    int count = 0;

    fpter = fopen("lib.csv","r");

    while(fgets(a,500,fpter)!=NULL){

        count++;
    }

    printf("Total books: %d\n", count);

    fclose(fpter);
}
int main(){
    int num,lo;
    fpter=fopen("lib.csv","a");
    if(fpter==NULL){
        printf("file does't exit\n");        
    }
    else{
        printf("file opened successfully\n");
        // fprintf(fpter,"title,auther_name,number\n");
    }
    enter();
    printf("number of atmat:");
    scanf("%d",&lo);
    for(int i=0;i<lo;i++){
    printf("\nenter your choise:");
    scanf("%d",&num);
    switch (num)
    {
    case 1:
    Add_new_book();
        break;
    case 2:
    Display_all_books();
        break;
    case 3:
    Search_book();
        break;
    case 4:
    Issue_book();
        break;
    case 5:
    Return_book();
        break;
    case 6:
    Delete_book_record();
        break;
    case 7:
    Count_total_books();
        break;
    default:
        break;
    }
    }
fclose(fpter);
}
