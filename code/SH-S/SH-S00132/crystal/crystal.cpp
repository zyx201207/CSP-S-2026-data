#include <cstdio>

long a[500000]={};

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long n,m,diff,i;
    scanf("%ld %ld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    diff=a[1]-a[0];
    for(i=1;m>=0;i++)
        m-=diff*i;
    printf("%ld",i-1);
    fclose(stdin);
    fclose(stdout);
    return(0);
}
