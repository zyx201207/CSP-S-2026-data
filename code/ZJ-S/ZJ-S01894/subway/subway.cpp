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

constexpr ll INF = 1e18, INF_thr = 1e17;

constexpr int fn = 5e5, gk = 500;
constexpr int N = fn + 10, K = gk + 10;

int tp;

int n, m, d, qn;
ll a[N]; vector<pair<int, ll>> E[N];

ll dis[K][K];
void preproc() {
	for (int x = 1; x <= n; ++x) for (int y = 1; y <= n; ++y) dis[x][y] = INF;
	for (int x = 1; x <= m; ++x) {
		for (auto i = E[x].begin(); i < E[x].end(); ++i) {
			for (auto j = next(i); j < E[x].end(); ++j) {
				Min(dis[i->first][j->first], i->second + j->second);
				Min(dis[j->first][i->first], i->second + j->second);
			}
		}
	}
	for (int x = 1; x <= n; ++x) dis[x][x] = 0;

	for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) Min(dis[i][j], dis[i][k] + dis[k][j]);
	return;
}

void NamespaceMain() {
	tp = rd(), n = rd(), m = rd(), d = rd(), qn = rd();
	for (int i = 1; i <= m; ++i) a[i] = rd();
	for (int i = 1; i <= n; ++i) {
		int cnt = rd();
		for (int _ = 1; _ <= cnt; ++_) {
			int x = rd(); ll t = rd();
			E[x].emplace_back(i, t);
		}
	}

	preproc();

	for (int h = 1; h <= qn; ++h) {
		int x = rd(), y = rd();
		ll res = INF;
		for (auto &p : E[x]) for (auto &q : E[y]) Min(res, dis[p.first][q.first] + p.second + q.second);
		res += a[x] + a[y];
		// #warning assert
		// assert(res < INF_thr);
		// if (res >= INF_thr) {
		// 	cerr bug(x) bug(y) bug(siz(E[x])) bug(siz(E[y])) bug(res) << endl;
		// 	assert(0);
		// }
		wrln(res);
	}
	return;
}
}
int main() {
	ignore = freopen("subway.in", "r", stdin);
	ignore = freopen("subway.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}