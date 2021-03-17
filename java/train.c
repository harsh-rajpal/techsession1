#include<stdio.h>
struct employee
{
    char name[10];
    int age;
    int empid;
    char city[10];
    char lang[10];
    float sal;
    char gen[10];   
};

int main(){
    struct employee e;
    {
        printf("enter the employee name:\n");
        scanf("%[^\n]%*c",&e.name);
        printf("enter the employee age :\n");
        scanf("%d",e.age);
        printf("enter the employee ID\n");
        scanf("%d",&e.empid);
        printf("enter the employee city in small case\n");
        scanf("%[^\n]%*c",&e.city);
        printf("enter the language:\n");
        scanf("%[^\n]%*c",&e.lang);
        printf("enter the emmployee salary:\n");
        scanf("%f",&e.sal);
        printf("enter the empolyee gender: \n");
        scanf("%[^\n]%*c",&e.gen);
        if(e.empid>105 && e.empid<110 && e.city== "vellore" && e.lang=="tamil" ){
            printf("the salary of such employees are %f \n",&e.sal);
        }
    };
    
    return 0 ;
}