// #include<stdio.h>
// #include<string.h>
// struct employee{
//     int eid;
//     char ename[100];
// };
// void display();
// int main(){
//     struct employee e;
//     {
//         e.eid=101;
//         strcpy(e.ename,"Ram");
//         display();
//     };
    
    
//     return 0 ;
// }
// void display(){
//     printf("%d",e.eid);
//     printf("%s",e.ename);
// }
#include<stdio.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
};

int main(){
    int i=5;int j=10;
    printf("%d %d",i,j);
    swap(&i,&j);
    printf("\n%d %d",i,j);
    
    return 0 ;
}