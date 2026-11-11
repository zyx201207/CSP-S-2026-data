#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,a[500005],m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,sum=0,ans=0;
    for(ll r=1;r<=n;r++)
    {
        sum+=(r-l)*(a[r]-a[r-1]);
        while(sum>m)sum-=a[r]-a[l++];
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
