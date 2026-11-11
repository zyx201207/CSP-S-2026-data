#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pli pair<long long,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fi first
#define se second
#define pb push_back
template<class _T>
void ckmax(_T &x, _T y) {
	x = max(x, y);
}
template<class _T>
void ckmin(_T &x, _T y) {
	x = min(x, y);
}
bool MST;
#define inf 0x3f3f3f3f
#define N 501010
int c, n, m, d, q;
int w[N], k;
int a, t;
vector<pli>g[N];
int ft, ed;
int dis[N];
priority_queue<pli, vector<pli>, greater<pli> > p;
void dij() {
	p.push({0, ft});
	dis[ft] = 0;
	while (!p.empty()) {
		pli now = p.top();
		p.pop();
		if (now.fi != dis[now.se])continue;
		int u = now.se;
		if (u == ed) {
			cout << dis[u] + w[ft] + w[ed] << "\n";
			return;
		}
		for (auto&nxt : g[u]) {
			int v = nxt.se, w = nxt.fi;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				p.push({dis[v], v});
			}
		}
	}
}
void clear_() {
	rep(i, 1, m + n) {
		dis[i] = inf;
	}
}
void solve_() {
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		cin >> k;
		rep(j, 1, k) {
			cin >> a >> t;
			g[a].pb({t, m + i});
			g[m + i].pb({t, a});
		}
	}
	while (q--) {
		cin >> ft >> ed;
		clear_();
		dij();
	}
}
bool MED;
signed main() {
//	cerr << abs(&MST - &MED) / 1024 / 1024 << "MB\n";
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve_();
	}
	return 0;
}
