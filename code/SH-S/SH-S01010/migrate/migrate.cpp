#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000005

int c;
int n;
long long d, x[N];
pair<long long, int> f[305][305];
pair<long long, int> operator +(const pair<long long, int> &x, const pair<long long, int> &y) {
	return {x.first + y.first, x.second * y.second};
}
pair<long long, int> min(const pair<long long, int> &x, const pair<long long, int> &y) {
	if (x.first > y.first) return y;
	if (x.first < y.first) return x;
	return {x.first, x.second + y.second};
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (c == 11 || c == 12) {
		if (n < 4) {
			cout << 0 << '\n';
			return ;
		}
		long long D = x[2] - x[1];
		if (d >= 2*D) {
			cout << max(n-(d/D)*2+1, 0ll) << '\n';
		} else {
			cout << 0 << '\n';
		}
		return ;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = {2e9, 0};
	for (int i = 1; i <= n; i++) {
		f[i][i] = {0, 1};
		for (int j = i+1; j <= n && x[j]-x[i] <= d; j++)
			f[i][j] = f[j][i] = {1, 1};
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i < k; i++)
			for (int j = k+1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++) {
			if (f[i][j].second == 2) ans++;
		}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T = 1;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
