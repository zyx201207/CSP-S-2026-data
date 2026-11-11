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

int n; ll m, a[N];

void NamespaceMain() {
	n = rd(), m = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();
	sort(a + 1, a + n + 1);

	int p = 0; ll cost = 0; // (p, i]
	ll ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (i > 1) cost += ll(i - 1 - p) * (a[i] - a[i - 1]);
		while (p < i && cost > m) {
			++p;
			cost -= (a[i] - a[p]);
		}
		Max(ans, ll(i - p));
	}
	wrln(ans);
	return;
}
}
int main() {
	ignore = freopen("crystal.in", "r", stdin);
	ignore = freopen("crystal.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}