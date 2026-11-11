#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
using ll = long long;

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

const int N = 2e6 + 5;
ll x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, t; cin >> c >> t;
	while (t--) {
		int n; ll d; cin >> n >> d;
		rep(i, 0, n) cin >> x[i];
//		if (11 <= c && c <= 12) {
			ll l = d / (x[1] - x[0]);
			if (l <= 1) cout << 0;
			else cout << max(n - 2 * l + 1, 0LL);
			cout << "\n";
//		}
	}
	flush();
	return 0;
}
