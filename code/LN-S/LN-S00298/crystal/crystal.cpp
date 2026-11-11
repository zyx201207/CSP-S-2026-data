#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500030];
bool check(long long x)
{
    long long ans=0;
    for(long long i=1;i<=x;i++)
    {
        ans+=a[x]-a[i];
    }
    if(ans<=m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    long long l=1,r=n;
    long long sum=0;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            sum=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    printf("%lld",sum);
    return 0;
}

