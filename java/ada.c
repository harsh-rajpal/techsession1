int main()
{
 
    int n, j;
    int i=0,rsum=0,lsum=0, a, b;
    
 scanf("%d",&n);
    int a[n][n];
    
 for(int a = 0; a < n; a++)
 {
       for(int b = 0; b < n; b++)
    {
         
          scanf("%d",&a[a][b]);
       }
    }
 
  while(i<n)
  {
    rsum=rsum+a[i][i];
    i++;
  }
    
 j=n-1,i=0;
    
  while(i<n)
  {
    lsum=lsum+a[i][j];
    i++;
    j--;
  }
    
 printf("%d",abs(rsum-lsum));
    return 0;
}