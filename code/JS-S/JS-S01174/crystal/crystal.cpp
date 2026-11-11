#include <bits/stdc++.h>
const int N = 5e5 + 10;
#define ll long long
using namespace std;
ll m, a[N], s[N];
int n, ans;
int fnd(int x)
{
    int l = 1, r = x, it = x;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        ll sum = s[x] - s[mid - 1];
        ll req = (x - mid + 1) * a[x];
        if (req - sum <= m) it = mid, r = mid - 1;
        else l = mid + 1;
    }
    return x - it + 1;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) ans = max(ans, fnd(i));
    cout << ans << "\n";
    return 0;
}
