#include<bits/stdc++.h>
using namespace std;
long long n,sum[500005],a[500005],m;
bool check(long long x)
{
    for(long long i=x;i<=n;i++)
        if(a[i]*x-sum[i]+sum[i-x]<=m)
            return true;
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    long long l=1,r=n;
    while(l<=r)
    {
        long long mid=l+r>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<r;
    return 0;
}
