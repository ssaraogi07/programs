#include<stdio.h>
int main()
{
long long int t,i,n,k,ans;
scanf("%lld",&t);
while(t--)
{
scanf("%lld %lld",&n,&k);
if(k==1)
    printf("1\n");
else if(k>(n/2))
 {
    ans=-1;
    printf("%lld\n",ans);
 }
else
    {
    ans=1;
    for(i=1;i<=k;i++)
    {
    ans=2*i;
    printf("%lld ",ans);
    }
    printf("\n");
    }
}
return 0;
}
