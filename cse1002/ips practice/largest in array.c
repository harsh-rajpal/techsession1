#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        
    }
    for(int c=0;c<n;c++)
    {
        if(b[0]<b[c]){
            b[0]=b[c];
        }
    }
    printf("%d",b[0]);
    return 0;
}


