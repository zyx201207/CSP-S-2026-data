#include <bits/stdc++.h>
using namespace std;
int a[100005], dp[100005], l[100005];

bool cmp(int a, int b) {
	if (a == 0)
		return b < a;
	if (b == 0)
		return a < b;
	return a < b;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int u, z, n, d;
	cin >> u;
	cin >> z;
	for (int q = 1; q <= z; q++) {
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int u = 1; u <= n - d; u++) {
			dp[u] = 0;
			for (int i = u + 1; i <= n; i++) {
				for (int j = 1; j <= d; j++) {
					if (i - j  >= u) {
						l[j] = dp[i - j] + 1;
					}
				}
				sort (l, l + d + 1, cmp);
				if (l[1] == l[2] && l[2] != l[3]) {
					ans++;
				}
				dp[i] = l[1];
				for (int i = 1; i <= 1000; i++) {
					l[i] = 0;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}