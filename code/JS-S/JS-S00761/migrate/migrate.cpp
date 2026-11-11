#include <bits/stdc++.h>
using namespace std;
long long c,T;
long long n,d;
long long a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while (T--)
    {
        scanf("%lld%lld",&n,&d);
        for (long long i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        long long dep=a[2]-a[1];
        if (a[n]-a[1]<=d)
        {
            printf("%lld\n",0);
            return 0;
        }
        long long w=d/dep;
        long long s=w*2-1;
        long long ans=0;
        long long dh=d;
        while (s>1)
        {
            if (n-s*dep>0 && s*dep>dh)
                ans+=(n-s*dep)/dep;
            d-=dep;
            w=d/dep;
            s=w*2-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
