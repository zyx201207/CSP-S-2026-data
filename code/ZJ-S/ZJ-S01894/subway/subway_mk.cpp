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

	mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
	inline ll get_rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rnd); }
	inline ll get_rnd(ll l, ll r, ll t) {
		ll res = get_rnd(l, r);
		while (t > 0) Max(res, get_rnd(l, r)), --t;
		while (t < 0) Min(res, get_rnd(l, r)), ++t;
		return res;
	}
}

constexpr int fn = 2e6;
constexpr int N = fn + 10;

int tp;

int n, m, d, qn;
vector<pair<int, ll>> F[N];

void NamespaceMain() {
	tp = 0;
	n = 500, m = 2.5e4, d = 20, qn = 1e5;
	wrln(tp, n, m, d, qn);
	for (int i = 1; i <= m; ++i) wrsp(get_rnd(1, 1e9));
	wrln();
	for (int i = 1; i <= m; ++i) {
		set<int> st;
		for (int _ = 1; _ <= d; ++_) {
			int x; ll t = get_rnd(1, 1e9);
			do x = get_rnd(1, n); while (st.count(x));
			st.insert(x);
			F[x].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= n; ++i) {
		assert(!F[i].empty());
		wrln(siz(F[i]));
		for (auto &pi : F[i]) wrsp(pi.first, pi.second);
		wrln();
	}
	for (int h = 1; h <= qn; ++h) {
		int x, y;
		do x = get_rnd(1, n), y = get_rnd(1, n); while (x == y);
		wrln(x, y);
	}
	return;
}
}
int main() {
	ignore = freopen("subway.in", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}