#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long a[N];
long long d;
int c, t, ans = 0;

void dfs(int x, int y) {
	if (x == y) {
		ans++;
	}
	if (a[x + 1] - a[x] > d)
		return ;
	for (int i = x + 1; i <= y; i++) {
		if (a[i] - a[x] > d) {
			dfs(i, y);
			return ;
		}
	}
	ans++;
}

void solve() {
	int n;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = 0;
	if (c >= 11 && c <= 12) {
		long long off = abs(a[2] - a[1]);
		if (d < off || d > off * 2) {
			cout << "0\n";
		} else {
			long long res = n * n / 2;
			cout << res << "\n";
		}
	}
	if (c >= 1 && c <= 10) {
		int total = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = 0;
				dfs(i, j);
				if (ans == 2) {
					total++;
				}
			}
		}
		cout << total << "\n";
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}