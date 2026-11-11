#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = (s); i <= (e); i++)
#define dep(i, s, e) for (int i = (s); i >= (e); i--)
#define sz(x) (int)x.size()
#define ppc(x) __builtlin_popcnt(x)
#define pub push_back
#define pii pair < int, int >
#define fi first
#define se second
using namespace std;

const int N = 505, M = 5e5 + 5;
#define int long long
#define ll long long
#define i28 __int128

vector < pii > v[M];
int f[N][N], w[M];

inline void cm(int &a, int b)
{
    a = min(a, b);
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, n, m, d, q;
    cin >> n >> n >> m >> d >> q;
    rep(i, 1, m)
        cin >> w[i];
    rep(i, 1, n)
        rep(j, 1, n)
            f[i][j] = i == j ? 0 : 5e17;
    
    int k, to, ti;
    rep(i, 1, n)
    {
        cin >> k;
        rep(j, 1, k)
        {
            cin >> to >> ti;
            v[to].pub({i, ti});
        }
    }
    rep(i, 1, m)
    {
        for (auto e1 : v[i])
            for (auto e2 : v[i])
                cm(f[e1.fi][e2.fi], e1.se + e2.se);
    }
    rep(i, 1, n)
        rep(j, 1, n)
            cm(f[i][j], f[j][i]), cm(f[j][i], f[i][j]);

    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    
    int x, y, dis;
    rep(i, 1, q)
    {
        cin >> x >> y;
        dis = 5e17;
        for (auto e1 : v[x])
            for (auto e2 : v[y])
                dis = min(dis, f[e1.fi][e2.fi] + e1.se + e2.se);
        cout << dis + w[x] + w[y] << "\n";
    }
    return 0;
}