#include<stdio.h>
#include<stdlib.h>
struct employee
{
    int id;
    char name[30];
    float sal;
};


int main(){
    struct employee *e;
    {
     e=(struct employee*)malloc(sizeof(struct employee)); 
     printf("enter the id of employee\n");
     scanf("%d",&e->id);
     printf("enter the name of employee: \n");
     scanf("%s",e->name);
     printf("enter the salary of employee: \n");
     scanf("%f",&e->sal);
     printf("ID stored is %d\n",e->id);
     printf("Name is %s\n",e->name);
     printf("Salary of employee is %f",e->sal);

    }
    
    return 0 ;
}