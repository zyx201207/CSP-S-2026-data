#include<bits/stdc++.h>
using namespace std;

void io() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

using ll = long long;

ll c, n, m, d, q, w[500020], x[100020], y[100020];
vector<ll> a[510], t[510];

ll G[1010][1010];
struct node {
    ll x, v;
};
bool operator> (node x, node y) {
    return x.v > y.v;
}
priority_queue<node, vector<node>, greater<node>> Q;
ll dis[1010];
ll calc(ll s, ll t) {
    memset(dis, -1, sizeof dis);
    while (Q.size()) Q.pop();
    Q.push({s, 0});
    while (Q.size()) {
        auto x = Q.top();
        ll u = x.x, v = x.v;
        Q.pop();
        if (dis[u] != -1) continue;
        dis[u] = v;
        for (ll i = 1; i <= m; ++i) {
            if (dis[i] == -1 && G[u][i] != -1) {
                Q.push({i, dis[u] + G[u][i]});
            }
        }
    }
    return dis[t] + w[s] + w[t];
}

int main() {
    io();
    
    cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (ll i = 1; i <= n; ++i) {
        ll k;
        cin >> k;
        a[i].resize(k + 1);
        t[i].resize(k + 1);
        for (ll j = 1; j <= k; ++j) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (ll i = 1; i <= q; ++i) {
        cin >> x[i] >> y[i];
    }
    
    memset(G, -1, sizeof G);
    for (ll i = 1; i <= n; ++i) {
        for (ll u = 1; u < a[i].size(); ++u) {
            for (ll v = u + 1; v < a[i].size(); ++v) {
                if (G[a[i][u]][a[i][v]] == -1) G[a[i][u]][a[i][v]] = G[a[i][v]][a[i][u]] = t[i][u] + t[i][v];
                else G[a[i][u]][a[i][v]] = G[a[i][v]][a[i][u]] = min(G[a[i][u]][a[i][v]], t[i][u] + t[i][v]);
            }
        }
    }
    
    for (ll qq = 1; qq <= q; ++qq) {
        cout << calc(x[qq], y[qq]) << '\n';
    }

	cout.flush();
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
