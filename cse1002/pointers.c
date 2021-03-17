#include<stdio.h>

int main(){
    int gradelist[8]={92,85,75,88,79,54,34,96};
    int *mygrades=gradelist;
    printf("%d\n",gradelist[1]);
    printf("%d",*mygrades);
    printf("\n%d",*mygrades++);
    
    
    return 0 ;
}