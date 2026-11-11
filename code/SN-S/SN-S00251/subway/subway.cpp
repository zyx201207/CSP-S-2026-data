#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct way
{
    int nxt;
    int belone;
};

struct q_st
{
    int u, belone;
    ll cur_val;
};

ll bfs(int n, int x, int y,
       const vector<vector<way>>& g, const vector<vector<ll>>& t)
{
    queue<q_st> q;
    vector<ll> dist(n+1, 1ll << 60);
    dist[x] = 0;
    for (way w : g[x]){
        q.push({x, w.belone, t[w.belone][x]});
    }
    while (!q.empty())
    {
        int u, b;
        ll cur;
        q_st tmp = q.front(); q.pop();
        u = tmp.u, b = tmp.belone, cur = tmp.cur_val;

        for (way w : g[u]){
            if (w.nxt == u) continue;
            ll new_d;
            if (w.belone == b){
                new_d = cur - t[b][u] + t[b][w.nxt];
                if (u == x) new_d += t[b][u];
            }
            else {
                new_d = cur + t[w.belone][u] + t[w.belone][w.nxt];
            }

            if (new_d < dist[w.nxt]){
                dist[w.nxt] = new_d;
                q.push({w.nxt, w.belone, new_d});
            }
        }
    }
    return dist[y];
}

void solve()
{
    int n, m, d,q;
    cin >> m >> n >> d >> q;
    vector<ll> w(n+1);
    for (int i = 1; i <= n; i++)    cin >> w[i];
    vector<vector<way>> g(n+1);
    vector<vector<ll>> t(m, vector<ll>(n+1, 0));
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int pre;
        for (int j = 0; j < k; j++)
        {
            int u;
            cin >> u;
            if (j != 0)
            {
                g[pre].push_back({u, i});
                g[u].push_back({pre, i});
            }
            pre = u;
            ll tim;
            cin >> tim;
            t[i][u] = tim;
        }
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << bfs(n, x, y, g, t)+w[x]+w[y] << endl;
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;

    solve();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
