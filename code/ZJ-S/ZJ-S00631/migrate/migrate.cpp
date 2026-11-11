#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
using ll = long long;

int n, Typ, f[N], g[N], s[N];
int l[N], r[N], pre[N], suf[N];
ll x[N], d;

void solve1() {
	int res = 0;
	for (int i = 1; i <= n; i ++ ) pre[i] = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j <= n; j ++ ) g[j] = l[j] = r[j] = s[j] = 0;
		for (int j = i; j <= n; j ++ ) f[j] = 1e9; f[i] = 0; l[0] = r[0] = i; g[i] = 1; s[i] = 1;
		for (int j = i + 1; j <= n; j ++ ) {
			int p = pre[j];
			p = max(p, i);
			if (p == j) break ;
			f[j] = f[p] + 1; if (f[j] != f[j - 1]) r[f[j - 1]] = j - 1, l[f[j]] = j;
			int q = r[f[p]];
			if (s[q] - s[p - 1] >= 3) g[j] = 3;
			else g[j] = s[q] - s[p - 1];
			s[j] = s[j - 1] + g[j];
		}
		for (int j = i + 1; j <= n; j ++ ) if (g[j] == 2) res ++ ;
	} cout << res << '\n';
}
void solve2() {
	ll s = x[2] - x[1]; ll m = d / s; int cnt = 0;
	if (m == 1) {
		cout << "0\n";
		return ;
	}
	for (int i = 1; i <= n - 1; i ++ ) {
		if (i == 2 * m - 1) cnt += n - i;
	} cout << cnt << '\n';
}
void solve3() {
	ll res = 0;
	for (int i = 1; i <= n; i ++ ) pre[i] = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
	for (int i = 1; i <= n; i ++ ) suf[i] = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
	for (int i = 1; i <= n; i ++ ) {
		if (x[n] - x[i] <= d) continue ;
		int l = suf[i] + 1, r = n;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (suf[i] - pre[mid] + 1 < 2) r = mid - 1;
			else l = mid;
		}
		int pr = l;
		l = suf[i] + 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (suf[i] - pre[mid] + 1 > 2) l = mid + 1;
			else r = mid;
		} int pl = r;
		if (suf[i] - pre[pr] + 1 != 2) continue ;
		res += max(0, pr - pl + 1);
	} cout << res << '\n';
}

int cn = 0;
void mian() {
	cin >> n >> d; cn ++ ;
	for (int i = 1; i <= n; i ++ ) cin >> x[i];
	bool flg = 1;
	for (int i = 2; i < n; i ++ ) flg &= (2 * x[i] == x[i - 1] + x[i + 1]);
	if (n <= 5000) solve1();
	else if (flg) solve2();
	else if (x[n] - x[1] <= 2 * d) solve3();
}

int main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> Typ >> T;
	while (T -- ) mian(); 
	return 0;
}
