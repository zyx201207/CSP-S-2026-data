#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 505, M = 5e5 + 5;

#ifdef __linux__
#define _J253 getchar_unlocked
#else
#define _J253 _getchar_nolock
#endif

ll read() {
	ll res = 0;
	char c = _J253();
	while (!isdigit(c))c = _J253();
	while (isdigit(c))res = res * 10 + c - '0', c = _J253();
	return res;
}

ll cc, n, m, d, q, w[M], a[N][N];
ll x, y, z;
struct qq {
	ll t, x;
};
vector<qq>c[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> cc >> n >> m >> d >> q;
	memset(a, 0x3f, sizeof a);
	for (int i = 1; i <= n; i++)a[i][i] = 0;
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		x = read();
		for (int j = 1; j <= x; j++) {
			y = read(), z = read();
			for (auto k : c[y]) a[i][k.t] = a[k.t][i] = min(a[i][k.t], k.x + z);
			c[y].pb({i, z});
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	while (q--) {
		x = read(), y = read();
		ll ans = 1e18;
		for (auto i : c[x]) {
			for (auto j : c[y]) {
				ans = min(ans, i.x + j.x + a[i.t][j.t]);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
