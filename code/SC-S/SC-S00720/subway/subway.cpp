#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
int k[505], a[505][505], t[505][505];
int x[100005], y[100005];
long long ans;
void find_re(int x, int y, long long &value, int nl, int st) {
	bool f = 0;
	for (int j = st; j <= k[nl]; j++) {
		if (a[nl][j] == y) f = 1;
	}
	if(f == 1) {
		for (int z = 1; z <= k[nl]; z++) {
			if (a[nl][z] == y) return;
			ans += t[nl][z];
		}
	}
	else {
		ans += t[nl][st];
		nl++;
		for (int z = 1; z <= k[nl]; z++) {
			if (a[nl][z] == a[nl][st]) {
				find_re(a[nl][z], y, ans, nl, z);
				return;
			}
		}
	}
	
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m; i++) {
		cin >> w[i];
	}
	cout << w[m];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
		ans = w[x[i]] ;
		find_re(x[i], y[i], ans, 1, 1);
		cout << ans << "\n";
	}
	return 0;
}
