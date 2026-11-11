#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
namespace IO {
const int SIZ = 1 << 20;
char buf[SIZ], *nw, *ed;
inline char getchar() {
	if (nw == ed) ed = buf + fread(buf, sizeof(char), SIZ, stdin), nw = buf;
	return *(nw++);
}
template<typename T> void read(T &x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	x *= f;
}
template<typename T, typename ...Args> void read(T &x, Args &...args) {
	read(x), read(args...);
}
}
using IO::read;
const int N = 1e6 + 10;
vector<int> e[N];
struct Edge {
	int u, v;
} ke[N];
int n, k;
namespace BF_1_10 {
const int N = 5000;
int bu, bv, d[N], ans[2][N], fa[N];
vector<int> pts;
set<int> rem[N];
inline void dfs(int u, int pa) {
	pts.push_back(u);
	fa[u] = pa;
	rem[u].clear();
	for (auto v : e[u]) {
		int tu = u, tv = v;
		if (tu > tv) swap(tu, tv);
		if (tu == bu && tv == bv) continue;
		rem[u].insert(v);
		if (v == pa) continue;
		dfs(v, u);
	}
}
inline void calc(int *dst) {
	if (pts.size() <= 1) {
		fill(dst, dst + n + 1, 1);
		return;
	}
	vector<int> le, ne;
	for (auto x : pts) if (rem[x].size() == 1) le.push_back(x);
	int tot = pts.size();
	dst[0] = tot;
	for (int i = 1; i <= n; i++) {
//		cout << i << " -----=====\n";
		for (auto x : le) {
			if (rem[x].empty()) continue;
			int fa = *rem[x].begin();
			if (rem[fa].find(x) == rem[fa].end()) continue;
			rem[fa].erase(rem[fa].find(x));
			if (rem[fa].size() == 1) ne.push_back(fa);
//			cout << x << " " << fa << endl;
		}
//		cout << le.size() << endl;
		tot -= le.size();
		dst[i] = max(tot, 1);
		swap(le, ne);
		ne.clear();
	}
}
inline void solve() {
	int as = n;
	for (int i = 1; i < n; i++) {
		bu = ke[i].u, bv = ke[i].v;
		if (bu > bv) swap(bu, bv);
//		cout << bu << " " << bv << endl;
		pts.clear();
		dfs(bu, 0);
		calc(ans[0]);
		pts.clear();
		dfs(bv, 0);
		calc(ans[1]);
		int p = n;
		for (int i = 0; i <= n; i++) {
			while (p > 0 && ans[0][i] + ans[1][p - 1] <= k) p--;
//			cout << i << " " << ans[0][i] << " " << ans[1][i] << endl;
			as = min(as, max(i, p));
		}
	}
	cout << as << "\n";
}
}
namespace BF_1314 {
inline void solve() {
	if (n == k) return cout << 0 << "\n", void();
	int m = n >> 1;
	m++;
	if (k >= m) return cout << 1 << "\n", void();
	int p1 = (m >> 1), p2 = ((m + 1) >> 1);
	int r1 = (k >> 1), r2 = ((k + 1) >> 1);
//	cout << p1 << " " << p2 << " " << r1 << " " << r2 << endl; 
	cout << max((p1 - r1 + 1) >> 1, (p2 - r2 + 1) >> 1) << "\n";
}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, ttt;
	read(c, ttt);
	while (ttt--) {
		read(n, k);
		for (int i = 1; i < n; i++) {
			int u, v;
			read(u, v);
//			cout << u << " " << v << endl;
			e[u].push_back(v);
			e[v].push_back(u);
			ke[i] = {u, v};
		}
		if (c <= 10) BF_1_10::solve();
		else if (c == 13 || c == 14) BF_1314::solve();
		for (int i = 1; i <= n; i++) e[i].clear();
	}
}
