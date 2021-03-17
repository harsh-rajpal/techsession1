#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
float calsal(float basic,float hra,float da)
{ 
  float sal;
  sal=basic+hra+da;
  return sal;
}
struct employee
{
  char name[40];
  int empid;
  char resident[15];
  int age;
  char language[15];
  char gender;
  float basic;
  float hra;
  float da;
};
int main()
{
  int n;
  printf("Enter the no of employees");
  scanf("%d",&n);
  struct employee e[n];
  int i;
  float sal;
  for(i=0;i<n;i++)
  {
    printf("Enter the employee name  of %d employee\n",i+1);
    getchar();
    scanf("%s[^\n]",e[i].name);
    printf("Enter the id of %d employee",i+1);
    scanf("%d",e[i].empid);
    printf("enter the city of employee \n");
    getchar();
    scanf("%s",e[i].resident);
    printf("enter the age of employee\n");
    scanf("%d",e[i].age);
    printf("enter the language of employee\n");
    getchar();
    scanf("%s",e[i].language);
    printf("enter the gender of employee as 'M' or 'F' or 'N'\n");
    getchar();
    scanf("%c",e[i].gender);
    printf("enter the salary of employee\n");
    scanf("%f",e[i].basic);
    printf("enter the hra of that employee\n");
    scanf("%f",e[i].hra);
    printf("enter the da of employee \n");
    scanf("%f",e[i].da);
   }
   for(i=0;i<n;i++)
   {
      if(tolower(e[i].gender)=='m')
      {
         if(e[i].age>45)
           {
              if(e[i].empid>105 && e[i].empid<110)
                { 
                   if(strcmp(e[i].resident,"vellore")==0)
                      {
                         if(strcmp(e[i].language,"Tamil")==0)
                           {
                              sal=calsal(e[i].basic,e[i].hra,e[i].da);
                              printf("%s",e[i].name);
                              printf("%f",sal);
                            }
                      }
                 }
            }
        }
     }  
return 0;
}
