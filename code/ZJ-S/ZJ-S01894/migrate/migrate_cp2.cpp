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
uchar db_jmp[N]; ll val[N];

ll W[N], g[N];
void solve_tc() {
	n = rd(), d = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();

	for (int i = 1, j = 1; i <= n; ++i) {
		Max(j, i);
		while (j + 1 <= n && a[j + 1] - a[i] <= d) ++j;
		if (j > i) jmp[i] = j;
		else jmp[i] = 0;
	}

	for (int i = 1; i <= n; ++i) db_jmp[i] = 0, val[i] = 0;
	for (int i = 1; i <= n; ++i) if (jmp[i]) {
		if (jmp[jmp[i]]) {
			if (jmp[i] - 1 > i) {
				if (a[jmp[i] - 1] + d >= a[jmp[jmp[i]]]) {
					if (jmp[i] - 2 <= i || a[jmp[i] - 2] + d < a[jmp[jmp[i]]]) {
						db_jmp[i] = 1;
					}
				}

				#warning kaih
				// (max(a[jmp[i]], a[jmp[i] - 2] + d), a[jmp[i] - 1] + d]
				ll L = max(a[jmp[i]], a[jmp[i] - 2] + d), R = a[jmp[i] - 1] + d;
				if (L < R) {
					val[i] = ll(upper_bound(a + 1, a + n + 1, R) - upper_bound(a + 1, a + n + 1, L));
				}
			}
		}
	}

	ll ans = 0;
	for (int i = n; i >= 1; --i) {
		W[i] = val[i], g[i] = 1;
		if (jmp[i]) {
			if (db_jmp[i]) {
				W[i] += val[jmp[i]] + g[jmp[jmp[i]]] - 1;
				++g[i];
			}
			else {
				W[i] += W[jmp[i]];
				g[i] += g[jmp[i]];
			}
		}
		ans += W[i];
		cerr bug(i) bug(val[i]) bug(W[i]) << endl;
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