#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],m;
ll sum[500010];
int n;
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        if((1ll*a[i]*x-(sum[i]-sum[i-x]))<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
