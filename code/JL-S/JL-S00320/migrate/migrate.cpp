#include<bits/stdc++.h>
using namespace std;
long long INF=1e12;
long long c,t,n,d,x[5000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        long long f=0,ff=1;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
        if(d==2) f=1;
        for(int i=1;i<=n-1;i++)
        {
            if(x[i+1]-x[i]!=1)
            {
                ff=0;
                break;
            }
        }
        if(f==1 && ff==1) printf("%lld\n",x[n]-3);
    }
    return 0;
}
