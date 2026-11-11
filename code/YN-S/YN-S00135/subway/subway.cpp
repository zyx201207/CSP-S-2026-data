#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, m, c, d, q, ans, w[N], k[505], pre;
int dis[N], vis[N];

struct edge {
	ll v, w;
};

struct Q {
	ll v, d;
};
vector <edge> e[N], E[505];
vector <ll> a[N];

void s(ll x, ll y) {
	memset(dis, sizeof(dis), 0x3f);
	memset(vis, sizeof(vis), 0);
	priority_queue <int> q;
	//q.push(v);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			edge jj;
			int v;
			jj.v = (ll)i;
			cin >> v >> jj.w;
			e[v].push_back(jj);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edge k, kk ;
			k.v = i, kk.v = j;
			k.w = kk.w = 1e12;
			E[j].push_back(k);
			E[i].push_back(kk);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			ll jv = e[i][j].v, jw = e[i][j].w;
			for (int k = j + 1; k < e[i].size(); k++) {
				ll kv = e[i][j].v, w = e[i][j].w + jw;
				edge jj, kk;
				jj.v = jv, kk. v = kv, jj.w = kk.w = w;
				E[jv].push_back(jj);
				E[kv].push_back(kk);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		ll x, y;
		ans = 1e18 + 5;
		for (int i = 0; i < e[x].size(); i++) {
			for (int j = 0; j < e[y].size(); j++) {
				ans = min(ans, E[e[x][i].v][e[y][j].v].w);
			}
		}
	}
	return 0;
}