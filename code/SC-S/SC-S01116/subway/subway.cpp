#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
using ll = long long;

const int M = 5e5 + 5;
const int N = 505;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll w[M];
vector<pair<int, ll>> g[M];
ll dist[N][N];

vector<pair<ll, int>> g2[N];

namespace fastio {
	const int S = 1 << 20;
	char ib[S], *ip = ib, *iq = ib;
	int gc() {
		if (ip == iq) iq = ib + fread(ib, 1, S, stdin), ip = ib;
		return ip == iq ? EOF : *ip++;
	}
	template<class T>
	bool read(T &x) {
		char ch = gc(); x = 0;
		while (ch <= 32 && ch != EOF) ch = gc();
		if (ch == EOF) return 0;
		while ('0' <= ch && ch <= '9')
			x = x * 10 + ch - '0', ch = gc();
		return 1;
	}

	char ob[S], *op = ob;
	void flush() { fwrite(ob, 1, op - ob, stdout); op = ob; }
	void pc(char c) { if (op == ob + S) flush(); *op++ = c; }
	template<class T>
	void write(T x) {
		static char st[64];
		int t = 0;
		do st[t++] = x % 10 + '0'; while (x /= 10);
		while (t) pc(st[--t]);
	}
}
using namespace fastio;

void dijkstra(int s, int n) {
	ll* dst = dist[s];
	memset(dst, 0x3f, sizeof(ll) * n); dst[s] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	bitset<N> vis; vis.reset();
	pq.push({0, s});
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto _ : g2[u]) {
			ll d = _.first; int v = _.second;
			if (!vis[v] && dst[v] > dst[u] + d)
				dst[v] = dst[u] + d, pq.push({dst[v], v});
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
//	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	read(c); read(n); read(m); read(d); read(q);
	memset(dist, 0x3f, sizeof dist);
	rep(i, 0, n) dist[i][i] = 0;
	rep(i, 0, m) read(w[i]);
	rep(i, 0, n) {
		int k; read(k);
		while (k--) {
			int a; ll t;
			read(a); read(t); --a;
			g[a].push_back({i, t});
		}
	}
//	rep(i, 0, n) printf("g[%d].size = %d\n", i, g[i].size()); puts("");
	rep(i, 0, m) if (g[i].size() > 1)
		for (auto _1 : g[i])
			for (auto _2 : g[i])
				dist[_1.first][_2.first] = min(dist[_1.first][_2.first], _1.second + _2.second);

	rep(i, 0, n)
		rep(j, 0, n)
			if (dist[i][j] < INF && i != j)
				g2[i].push_back({dist[i][j], j});
//	rep(i, 0, n) {
//		printf("g2[%d]: ", i);
//		for (auto [i, j])
//	}
	rep(i, 0, n)
		dijkstra(i, n);
//	rep(i, 0, n) {
//		rep(j, 0, n) printf("%lld ", dist[i][j]);
//		puts("");
//	}
	while (q--) {
		int x, y; read(x); read(y); --x, --y;
		ll mi = INF;
		for (auto _1 : g[x]) {
			for (auto _2 : g[y])
				mi = min(mi, dist[_1.first][_2.first] + _1.second + _2.second);
		}
		write(w[x] + w[y] + mi); pc('\n');
	}
	flush();
	return 0;
}
