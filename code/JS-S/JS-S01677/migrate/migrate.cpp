#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    long long n,d,x[1000005];
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld",&n,&d);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&x[j]);
        }
        long long num=x[2]-x[1],k;
        k=d/num;
        long long dis=2*k-1;
        printf("%lld\n",n-dis);
    }
    return 0;
}
