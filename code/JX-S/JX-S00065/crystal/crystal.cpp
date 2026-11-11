#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
LL a[N],sum[N];
LL n,m;
bool check(LL x)
{
    LL cnt=0;
    for(int i=x;i<=n;i++)
    {
        LL tot=x*a[i]-m;
        if(tot<=sum[i]-sum[i-x])return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    LL ans=0;
    LL l=1,r=n;
    LL mid=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(check(mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}
