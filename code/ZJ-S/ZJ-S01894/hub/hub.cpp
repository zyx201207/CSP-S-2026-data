#include<bits/stdc++.h>
using namespace std;

namespace MyNamespace {
typedef long long ll;
typedef unsigned char uchar;

inline namespace MyIO {
	inline ll rd() {
		char ch = getchar();
		ll s = 0, w = 1;
		while (!isdigit(ch)) {
			if (ch == '-') w = -1;
			ch = getchar();
		}
		while (isdigit(ch)) {
			s = (s << 3) + (s << 1) + (ch ^ 48);
			ch = getchar();
		}
		return (s * w);
	}
	template<typename T>
	inline void wr(T x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) wr(x / 10);
		putchar(x % 10 + 48);
		return;
	}
	inline void wrsp() {}
	template<typename T, typename... Args>
	inline void wrsp(T x, Args... args) { wr(x), putchar(' '), wrsp(args...); }
	inline void wrln() { putchar('\n'); }
	template<typename T>
	inline void wrln(T x) { wr(x), wrln(); }
	template<typename T, typename... Args>
	inline void wrln(T x, Args... args) { wrsp(x), wrln(args...); }
}

inline namespace Base {
	#define bug(x) << #x << '=' << (x) << ' '
	#define siz(A) int((A).size())

	template<typename T>
	constexpr inline T& Max(T &x, const T &y) { return x = max(x, y); }
	template<typename T>
	constexpr inline T& Min(T &x, const T &y) { return x = min(x, y); }
}

constexpr int fn = 1e6;
constexpr int N = fn + 10;

int tp;

int n, kn; vector<int> E[N];

int p, q, dep[N], fa[N];
uchar on_diam[N]; vector<int> D;
void dfs_dep(int x, int fr) {
	for (int v : E[x]) if (v != fr) {
		dep[v] = dep[x] + 1, fa[v] = fr;
		dfs_dep(v, x);
	}
	return;
}
void get_diam() {
	for (int x = 1; x <= n; ++x) on_diam[x] = 0;
	D.clear();

	dep[1] = 0, fa[1] = 0, dfs_dep(1, 0);
	p = max_element(dep + 1, dep + n + 1) - dep;
	// cerr bug(p) << endl;
	dep[p] = 0, fa[p] = 0, dfs_dep(p, 0);
	// for (int x = 1; x <= n; ++x) cerr bug(x) bug(dep[x]) << endl;
	q = max_element(dep + 1, dep + n + 1) - dep;
	// cerr bug(q) << endl;
	int u = q;
	while (u) {
		// cerr bug(u) << endl;
		D.push_back(u);
		on_diam[u] = 1;
		u = fa[u];
	}
	// cerr bug(siz(D)) << endl;
	return;
}

int mid, cnt; uchar used[N];
int dfs_cnt(int x, int fr, int could) {
	int h = 0;
	for (int v : E[x]) if (!on_diam[v] && v != fr) {
		Max(h, dfs_cnt(v, x, 1) + 1);
	}
	used[x] = 0;
	if (could && h >= mid) ++cnt, used[x] = 1;
	return h;
}
bool check() {
	if (mid == 0) return kn >= n;
	cnt = 0;
	if (siz(D) - 1 <= mid) return 1;
	if (mid * 2 >= siz(D) - 1) return 1;
	for (int x = 1; x <= n; ++x) used[x] = 0;
	int l, r;
	l = mid, r = siz(D) - 1 - mid;
	used[D[l]] = 1, dfs_cnt(D[l], 0, 0);
	used[D[r]] = 1, dfs_cnt(D[r], 0, 0);
	for (int i = l + 1; i < r; ++i) dfs_cnt(D[i], 0, 1);

	int lst = l, z = 0;
	for (int i = l + 1; i <= r; ++i) {
		if (used[i]) {
			Max(z, i - lst - 1);
			lst = i;
		}
	}
	Min(z, mid * 2 - 1);
	for (int i = l; i <= r; ++i) if (!used[i]) used[i] = 1, ++cnt;
	
	// #warning
	cnt -= z;
	// cerr bug(mid) bug(cnt) bug(kn) << endl;
	return cnt <= kn;
}
void solve_tc() {
	n = rd(), kn = rd();
	for (int x = 1; x <= n; ++x) E[x].clear();
	for (int i = 1; i < n; ++i) {
		int u = rd(), v = rd();
		E[u].push_back(v), E[v].push_back(u);
	}

	get_diam();
	// cerr << "a\n";
	// mid = 12001, check();

	int lef = -1, rig = n; // (lef, rig]
	while (lef + 1 < rig) {
		mid = (lef + rig) >> 1;
		(check() ? rig : lef) = mid;
	}
	wrln(rig);
	return;
}
void NamespaceMain() {
	tp = rd(); int T = rd();
	while (T--) solve_tc();
	return;
}
}
int main() {
	ignore = freopen("hub.in", "r", stdin);
	ignore = freopen("hub.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}