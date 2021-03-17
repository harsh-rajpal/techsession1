#include<stdio.h>
#include<string.h>
struct Book
{
    int bID;
    char bName[15];
    float bPrice;
    char auth[25];
    int year;
};
int main(){
    struct Book b;
    printf("Enter the book id: \n");
    scanf("%d",&b.bID);
    printf("enter the book name:\n");
    scanf("%s",&b.bName);
    printf("Enter book price:\n");
    scanf("%f",&b.bPrice);
    printf("Enter the name of author\n");
    getchar();
    scanf("%c",&b.auth);
    printf("enter the year:\n");
    scanf("%d",&b.year);
    if(b.year<2004){
        b.bPrice=b.bPrice/2;
        printf("book name is %s\n and book price is %f",b.bName,b.bPrice);

    }


}   

