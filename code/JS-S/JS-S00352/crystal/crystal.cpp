#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500005];
ll q[500005];
bool chk(int k)
{
    for (int i = 1; i <= (n - k + 1); i++)
    {
        ll qj = q[i + k - 1] - q[i - 1];
        ll nd = a[i + k - 1] * k - qj;
        if (nd <= m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) q[i] = a[i] + q[i - 1];
    int l = 1, r = n, mid, ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (chk(mid))
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
