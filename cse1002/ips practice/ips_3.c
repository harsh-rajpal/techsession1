#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a+c==b || a+b==c || b+c==a){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
//check if sum of two numbers is equal to third number or not when 3 numbers are entered.