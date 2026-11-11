#include<bits/stdc++.h>
#define int long long
using namespace std;
bool s1;
int a[500005],n,ans,mid,r,l=1,sum[500005],m;
bool check(int x)
{
    for(int i = 1;i<=n-x+1;i++)
    {
        if(sum[i+x-1]-sum[i-1]+m>=a[i+x-1]*x)
            return true;
    }
    return false;
}
bool t1;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    r = n;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r= mid-1;
        }
    }
    cout << ans;
    return 0;
}
