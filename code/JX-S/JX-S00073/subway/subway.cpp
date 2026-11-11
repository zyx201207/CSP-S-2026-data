#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXM = 5e5 + 5;

struct Node
{
    ll i;
    ll t;
};

ll c, n, m, d, q;
ll x, y, ans = 0;
ll w[MAXM];
vector<ll> g[MAXM];
vector<Node> tarr[MAXM];

void func()
{
    ans += w[x];
    ans += tarr[x][0].t;
    while (x != y)
    {
        x = g[x][1];
        ans += 2 * tarr[x][1].t;
    }
    ans += tarr[y][0].t;
    ans += w[y];
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;

    for (ll i = 1; i <= m; ++i)
    {
        cin >> w[MAXM];
    }
    for (ll i = 1; i <= n; ++i)
    {
        ll k;
        cin >> k;
        for (ll j = 1; j <= k; ++j)
        {
            ll a, t;
            cin >> a >> t;
            g[i].push_back(a);
            tarr[a].push_back({i, t});
        }
    }

    for (ll i = 1; i <= q; ++i){
        cin >> x >> y;
        ans = 0;
        func();
        cout << ans << "\n";
    }

    return 0;
}
