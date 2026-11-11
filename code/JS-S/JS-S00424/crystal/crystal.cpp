#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m,l,r,now,ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    while (r<=n)
    {
        while (now>m) now-=a[r]-a[l],++l;
        ans=max(ans,r-l+1);
        ++r,now+=(a[r]-a[r-1])*(r-l);
    }
    cout << ans;
    return 0;
}
