#include <bits/stdc++.h>
using namespace std;

using i32 = int; using i64 = long long;

#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
#define eb emplace_back
#define x first
#define y second

const i32 N = 1 << 20;
inline void cmax(i32& x, i32 y) { (y > x) && (x = y); }

i32 c, T;

i32 n, k;
i32 hson[N], dep[N], fa[N];
i32 D[N];
basic_string < i32 > e[N];

i32 mxx[N], see[N];

void dfs(i32 u) {
	for (i32 v : e[u]) if (v != fa[u]) {
		fa[v] = u, D[v] = D[u] + 1, dfs(v);
		dep[u] = max(dep[u], dep[v] + 1);
		if (dep[v] >= dep[hson[u]]) hson[u] = v;
	}
	mxx[u] = see[u] = -1e9;
	for (i32 v : e[u]) if (v != fa[u] && v != hson[u]) {
		if (dep[v] > mxx[u]) see[u] = mxx[u], mxx[u] = dep[v];
		else see[u] = max(see[u], dep[v]);
	}
}

basic_string < i32 > son[N];
priority_queue < pair < i32, i32 > > g;
bool vis[N];

i32 ans;

i32 Fu, Fv, chk, lca;
i32 orF, u, v;

inline i32 getA() {
	if (!chk) return max(orF, Fu + D[u]);
	return max(max(Fu + D[u], Fv + D[v]), D[u] + D[v] - D[lca] * 2);
}
inline i32 getB() { if (g.empty()) return 0; return g.top().x; }

inline bool plusk() {
	if (g.empty()) return 0;
	i32 u = g.top().y; g.pop();
	vis[u] = 1; if (fa[u]) son[fa[u]] += {u};
	for (auto v : e[u]) if (v != fa[u]) {
		g.push({dep[v], v});
	}
	return 1;
}
inline i32 getAdelu() {
	i32 x = son[u][0];
	i32 OorF = orF;
	i32 OFu = Fu;
	i32 mx = mxx[u], se = see[u];
	cmax(orF, mx + se);
	max(Fu, mx - D[u]);
	u = x;
	i32 res = getA();

	orF = OorF, Fu = OFu, u = fa[u];
	return res;
}
inline void delu() {
	i32 x = son[u][0];
	i32 mx = mxx[u], se = see[u];
	cmax(orF, mx + se);
	max(Fu, mx - D[u]);
	u = x;
}

inline i32 getAdelv() {
	i32 x = son[v][0];
	i32 OorF = orF;
	i32 OFv = Fv;
	i32 mx = mxx[v], se = see[v];
	cmax(orF, mx + se);
	max(Fv, mx - D[v]);
	v = x;

	i32 res = getA();
	orF = OorF, Fv = OFv, v = fa[v];
	return res;
}

inline void delv() {
	i32 x = son[v][0];
	i32 mx = mxx[v], se = see[v];
	cmax(orF, mx + se);
	max(Fu, mx - D[v]);
	v = x;
}

inline void solve() {
	cin >> n >> k;
	For (i, 1, n - 1) {
		i32 u, v; cin >> u >> v;
		e[u] += {v}, e[v] += {u};
	}
	dfs(1);
	g.push({ dep[1], 1 });
	For (i, 1, k) plusk();
	if (g.empty()) return cout << "0\n", void();

	orF = Fu = chk = 0, u = 1;
	ans = getA() + getB();

	while (1) {
		if (!chk) {
			if (son[u].size() == 1) {
				//尝试删除点u。计算u除了重儿子v，以外的mx, se
				i32 v = son[u][0];

				i32 mx = -1e9, se = -1e9;
				for (i32 p : e[u]) if (p != fa[u] && p != v) {
					if (dep[p] > mx) se = mx, mx = dep[p];
					else se = max(se, dep[p]);
				}
				
				if (!plusk()) break;
				orF = max(orF, mx + se), Fu = max(Fu, mx - D[u]);
				u = v; ans = min(ans, getA() + getB());
				if (getA() > getB()) break;
				continue;
			}
			if (son[u].size() > 2) break;

			//我要把u，分裂成x, y。两个点
			i32 x = son[u][0], y = son[v][0];
			//那么首先，我知道lca。然后仍然找到u的mx, se。
			i32 mx = -1e9, se = -1e9;
			for (i32 p : e[u]) if (p != fa[u] && p != x && p != y) {
				if (dep[p] > mx) se = mx, mx = dep[p];
				else se = max(se, dep[p]);
			}
			
			if (!plusk()) break;
			orF = max(orF, mx + se), Fu = max(Fu, mx - D[u]), lca = u;
			chk = 1, Fv = Fu;
			u = x, v = y; ans = min(ans, getA() + getB());
			if (getA() > getB()) break;
			continue;
		}
		//当有两个点u, v时。
		//我会选择，对A增加更慢的点删除。
		//并且若有两个儿子，就不能删。
		if (son[u].size() != 1 && son[v].size() != 1) break;
		if (son[u].size() != 1) delv();
		else if (son[v].size() != 1) delu();
		else {
			if (getAdelu() > getAdelv()) delv();
			else delu();
		}
		if (!plusk()) break;
		ans = min(ans, getA() + getB());
		if (getA() > getB()) break;
	}

	cout << ans << '\n';
}

inline void clr() {
	For(i, 1, n) {
		hson[i] = dep[i] = fa[i] = D[i] = 0;
		e[i].clear();
		son[i].clear();
		mxx[i] = see[i] = 0;
		vis[i] = 0;
	}
	while(!g.empty()) g.pop();
	Fu = Fv = chk = lca = orF = u = v = 0;
}


int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(), cin.tie(), cout.tie();
	
	cin >> c >> T;
	while (T--) solve();

	return 0;
}