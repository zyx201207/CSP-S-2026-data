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

constexpr int fn = 4e6;
constexpr int N = fn + 10;

int tp;

int n; ll d;
ll a[N]; int jmp[N];

void solve_tc() {
	n = rd(), d = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();

	for (int i = 1, j = 1; i <= n; ++i) {
		Max(j, i);
		while (j + 1 <= n && a[j + 1] - a[i] <= d) ++j;
		if (j > i) jmp[i] = j;
		else jmp[i] = 0;
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cerr << "\e[33m" bug(i) << "\e[0m" << endl;
		int l = i, r = i, k = 0;
		while (l <= r && jmp[r]) {
			cerr bug(l) bug(r) bug(k) << endl;
			int u = r + 1, v = jmp[r], w = k;
			if (l < r) {
				if (jmp[r - 1] + 1 > u) {
					Max(u, jmp[r - 1] + 1);
					w = 2;
				}
			}
			int p = r + 1, q = u - 1;
			if (k == 2) Max(p, jmp[l - 1] + 1);
			if (r - l >= 2) Max(p, jmp[r - 2] + 1);
			if (u > v) {
				if (k == 1) break;
				w = 1;
				l = p, r = q, k = w;
			}
			else {
				if (k != 1 && p <= q) {
					cerr << "add " bug(p) bug(q) << endl;
					ans += ll(q - p + 1);
				}
				l = u, r = v, k = w;
			}
			if (k == 1 && l <= r) {
				cerr << "add " bug(l) bug(r) << endl;
				ans += ll(r - l + 1);
			}
		}
	}
	wrln(ans);
	return;
}
void NamespaceMain() {
	tp = rd(); int T = rd();
	while (T--) solve_tc();
	return;
}
}
int main() {
	ignore = freopen("migrate.in", "r", stdin);
	ignore = freopen("migrate.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}