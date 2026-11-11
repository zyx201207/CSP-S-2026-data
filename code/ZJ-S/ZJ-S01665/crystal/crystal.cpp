#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+20;
int a[N];
int n,m;
// O(n)
bool check(int mid)
{
    int res = 0;
    for (int i=1;i<mid;i++)
        res += a[mid] - a[i];
    if (res <= m)
        return true;
    for (int l=2,r=mid+1;r<=n;l++,r++)
    {
        res -= (a[r-1] - a[l-1]);
        res += (mid-1) * (a[r] - a[r-1]);
        if (res <= m)
            return true;
    }
    return false;
}
signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    int l=0,r=n,ans=0;
    // O(log n)
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    // Sigma O(nlogn)
    cout << ans;
    return 0;
}