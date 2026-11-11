#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i)
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
#define fi first
#define se second
#define eb emplace_back
#define Sz(v) ((int)(v).size())
using namespace std;
typedef long long ll; // check ll
const int N = 1e6 + 10;
const int INF = 1e9;
int n, k;
pair<int, int> e[N];
namespace S1 {
	const int N = 15;
	vector<int> G[N];
	struct DSU {
		int fa[N];
		void Init(int n) {
			iota(fa, fa + n + 1, 0);
		}
		int Find(int u) {
			return fa[u] == u? u : fa[u] = Find(fa[u]);
		}
		void Union(int u, int v) {
			u = Find(u), v = Find(v);
			fa[v] = u;
		}
	} dsu;
	int Find(int u, int fat, int s) {
		if (fat && (s >> (u - 1) & 1)) return 0;
		int ret = INF;
		for (int v: G[u]) if (v != fat) {
			ret = min(ret, Find(v, u, s) + 1);
		}
		return ret;
	}
	void Clear() {
		FL(i, 1, n) G[i].clear();
	}
	void Main() {
		int ans = n + 1;
		FL(i, 1, n - 1) {
			int u = e[i].fi, v = e[i].se;
			G[u].eb(v), G[v].eb(u);
		}
		FL(s, 0, (1 << n) - 1) {
			if (__builtin_popcount(s) != k) continue;
			dsu.Init(n);
			FL(i, 1, n - 1) {
				int u = e[i].fi, v = e[i].se;
				if ((s >> (u - 1) & 1) && (s >> (v - 1) & 1)) {
					dsu.Union(u, v);
				}
			}
			int cnt = 0, mx = 0;
			FL(i, 1, n) if (s >> (i - 1) & 1) {
				cnt += (dsu.Find(i) == i);
			}
			FL(i, 1, n) {
				mx = max(mx, Find(i, 0, s));
			}
			if (cnt <= 2) {
//				cout << " s:" << s << ' ' << mx << endl; 
				ans = min(ans, mx);
			}
		}
		printf("%d\n", ans);
		Clear();
	}
}
void Solve() {
	scanf("%d %d", &n, &k);
	FL(i, 1, n - 1) {
		scanf("%d %d", &e[i].fi, &e[i].se);
	}
	if (n <= 10) {
		S1::Main();
	} else {
		printf("%d\n", 1);
	}
}
void Clear() {
	
}
int main() {
//	freopen("hub3.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int Cid, T;
	scanf("%d %d", &Cid, &T);
	while (T--) {
		Solve();
		Clear();
	}
	return 0;
}
