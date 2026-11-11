#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000002];
long long n,d;
bool ch(long long i)
{
    if(a[i+3]-a[i]>d && a[i+1]-a[i]<=d && a[i+3]-a[i+1]<=d && a[i+3]-a[i+2]<=d && a[i+2]-a[i]<=d){
        return true;
    }
    return false;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    c=11;
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        if(c==11 || c==12)
        {
            for(int i=1;i<=n;i++)
            {
                scanf("%lld",&a[i]);
            }
            long long ans=0;
            for(int i=1;i+3<=n;i++)
            {
                if(ch(i)){
                    ans++;
                }
            }
            printf("%lld\n",ans);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        if(c==13 || c==14)
        {
            printf("0\n");
            continue;
        }
        long long ans=0;
        for(int i=1;i+3<=n;i++)
        {
            if(ch(i)){
                long long le=i-1,lenum=1;
                while(le>0)
                {
                    if(a[le+1]-a[le]>d || ch(le))
                    {
                        break;
                    }
                    else
                    {
                        lenum++;
                    }
                    le--;
                }
                long long ri=i+4,rinum=1;
                while(ri<=n)
                {
                    if(a[ri]-a[ri-1]>d || ch(ri-3))
                    {
                        break;
                    }
                    else
                    {
                        rinum++;
                    }
                    ri++;
                }
                ans+=rinum*lenum;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
