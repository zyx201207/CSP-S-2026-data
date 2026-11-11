#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n, m, ans;
int a[N], b[N];
bool check(int x)
{
    for(int i=1;i<=n-x+1;i++)
    {
        int t1 = b[i - 1];
        int t2 = b[i + x - 1];
        int asum = t2 - t1;
        if(a[i + x - 1] * x - asum <= m) return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    int l = 1, r = n, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}