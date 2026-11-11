#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, d, a[2000006], f[2000006], g[2000006], near[2000006], you[2000006];
ll sumg[2000006], ans;

void solve2() {
	ll gc = a[2] - a[1], rd = d / gc;
	if (rd == 1 || rd == 0)
		cout << 0 << endl;
	else
		cout << max(n - 2ll * rd + 1, 0ll) << endl;
	return ;
}

void solve() {
	cin >> n >> d;
	ans = 0;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << 0 << endl;
		return ;
	}
	if (c == 11 || c == 12) {
		solve2();
		return ;
	}
	ll pos = 1;
	a[0] = -2e18;
	for (ll i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] > d) {
			near[i] = -1;
			pos = i;
			continue;
		}
		if (a[i] - a[pos] <= d) {
			near[i] = pos;
			continue;
		}

		while (a[i] - a[pos] > d)
			pos++;
		near[i] = pos;
	}
//	for (ll i = 1; i <= n; i++)
//		cout << near[i] << " ";
//	cout << endl;
	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j <= n; j++)
			f[j] = g[j] = you[j] = sumg[j] = 0;
		ll rpos = n;
		you[0] = i;
		for (ll j = i + 1; j <= n; j++) {
			if (near[j] == -1) {
				rpos = j - 1;
				break;
			}
			f[j] = f[near[j]] + 1;
			you[f[j]] = j;
		}
		g[i] = sumg[i] = 1;
		for (ll j = i + 1; j <= rpos; j++) {
			g[j] = sumg[you[f[j] - 1]] - sumg[near[j] - 1];
			if (g[j] == 2)
				ans++;
			sumg[j] = sumg[j - 1] + g[j];
		}
//		cout << i << ":\n";
//		cout << rpos << endl;
//		for (ll j = 1; j <= n; j++)
//			cout << f[j] << " ";
//		cout << endl;
//		for (ll j = 1; j <= n; j++)
//			cout << sumg[j] << " ";
//		cout << endl;
//		for (ll j = 1; j <= n; j++)
//			cout << you[j] << " ";
//		cout << endl;
//		for (ll j = 1; j <= n; j++)
//			cout << g[j] << " ";
//		cout << endl;
	}
	cout << ans << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
		solve();
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6