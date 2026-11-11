#include <bits/stdc++.h>
#define pii pair<int, int>
#define a first
#define b second
const int N = 2e6 + 10;
#define ll long long
using namespace std;
int n;
ll d, x[N];
pii f[N];
int chk(int l)
{
    int res = 0;
    for (auto &t : f) t = {1e9, 0};
    f[l] = {0, 1};
    for (int r = l + 1; r <= n; r++)
    {
        int minn = 1e9;
        for (int i = l; i < r; i++)
        {
            if (x[r] - x[i] > d) continue;
            minn = min(minn, f[i].a);
        }
        f[r].a = minn + 1;
        for (int i = l; i < r; i++)
        {
            if (x[r] - x[i] > d) continue;
            if (f[i].a > minn) continue;
            f[r].b += f[i].b;
        }
        res += (f[r].b == 2);
    }
    return res;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, T; cin >> c >> T;
    while (T--)
    {
        cin >> n >> d; int ans = 0;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) ans += chk(i);
        cout << ans << "\n";
    }
    return 0;
}
