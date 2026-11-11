#include <bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
using namespace std;
const int maxn=5e5+5;
int a[maxn],sum[maxn];
int n,m;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int l=1,r=i;
        while (l<r)
        {
            if ((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }   
    cout << ans << '\n';
    return 0;
}