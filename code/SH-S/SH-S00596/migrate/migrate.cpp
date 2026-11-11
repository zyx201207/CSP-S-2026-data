#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
using lonit = long long;

long long n, d, c;
long long ary[2'000'010];

map<int, int> dis;

int u, v;
bool can;

void dfs(int x, int ds)
{
    if (x == v)
    {
        ++dis[ds];
        return;
    }
    for (int i = x + 1; i <= v; ++i)
    {
        if (ary[i] - ary[x] <= d)
            dfs(i, ds + 1);
        else
            break;
    }
}

inline void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ary[i];
    }
    if (c == 13 || c == 14)
    {
        long long ans = n;
        ans *= 1ll * (n - 1);
        ans /= 2ll;
        cout << ans << '\n';
        return;
    }
    if (c == 11 || c == 12)
    {
        int x = ary[2] - ary[1];
        if (d < 2 * x)
            cout << "0\n";
        return;
    }
    int ans = 0;
    for (u = 1; u <= n; ++u)
    {
        for (v = u + 1; v <= n; ++v)
        {
            dis.clear();
            can = false;
            dfs(u, 0);
            for (pair<const int, int> &x : dis)
            {
                if (x.second == 2)
                    ++ans;
                break;
            }
        }
    }
    cout << ans << '\n';
    return;
}

int main()
{
    //    freopen("migrate.in", "r", stdin);
    //    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> c >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
