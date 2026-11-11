#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define fi first
#define se second
typedef vector <int> vi;
typedef vector <pii> vpi;
#define pb push_back

const int N = 500005;

int c, n, m, d, q, w[N], k, x, y;
vpi vv[N];
ll f[505][505];

void rd(int &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
template <class T> void wrt(T x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	int _ = clock();
	rd(c), rd(n), rd(m), rd(d), rd(q);
	rep(i, 1, m) rd(w[i]);
	rep(i, 1, n) {
		rd(k);
		while (k--) rd(x), rd(y), vv[x].pb({y, i});
	}
	memset(f, 0x3f, sizeof(f));
	rep(i, 1, n) f[i][i] = 0;
	rep(i, 1, m) {
		for (auto A : vv[i]) for (auto B : vv[i]) {
			ll &val = f[A.se][B.se];
			val = min(val, (ll)A.fi + B.fi);
		}
	}
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		rd(x), rd(y);
		ll ans = 1e18;
		for (auto A : vv[x]) for (auto B : vv[y]) {
			ans = min(ans, A.fi + B.fi + f[A.se][B.se]);
		}
		wrt(ans + w[x] + w[y]), putchar(10);
	}
//	cerr << clock() - _;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
