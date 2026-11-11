#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll c, n, m, d, q, w[500010], xx, y, v[510], ans = 1e18, s[510][500010];
vector<ll> x[510];
vector<ll> e[500010];

void dfs(ll id, ll tim)
{
    for (ll i : e[y])
    {
        if (id == i)
        {
            tim = tim + s[id][y] + w[y];
            ans = min(ans, tim);
            return;
        }
    }
    for (ll i : x[id])
    {
        for (ll j : e[i])
        {
            if (v[j] == 0){
                v[j] = 1;
                dfs(j, tim + s[j][i] + s[id][i]);
                v[j] = 0;
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        ll ki;
        cin >> ki;
        for (ll j = 1; j <= ki; j++)
        {
            ll a, t;
            cin >> a >> t;
            x[i].push_back(a);
            e[a].push_back(i);
            s[i][a] = t;
        }
    }
    while(q--)
    {
        ans = 1e18;
        for (ll i = 1; i <= n; i++)
        {
            v[i] = 0;
        }
        cin >> xx >> y;
        for (ll i : e[xx])
        {
            v[i] = 1;
            dfs(i, s[i][xx] + w[xx]);
            v[i] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}
