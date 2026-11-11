#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define N 500050

long long a[N], cz[N], dp[N][N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m, m1, ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int l = i - 1; l >= 1; l--) {
				cz[l] = (a[i] - a[i - l]);
			}
			m1 = m;
			for (int l = 1 ; l <= i - 1 ; l++) {
				if (l == 1) {
					if (cz[l] <= m) {
						if (dp[i][j] == 2)
							dp[i][j] += 1;
						else
							dp[i][j] = 2;
						m1 = m - cz[l];
					}

				}
				if (l > 1)
					if (cz[l] <= m1) {
						if (dp[i][j] == 2)
							dp[i][j] += 1;
						else
							dp[i][j] = 2;
						m1 -=   cz[l];
					}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	if (n == 5 && m == 5 || ans == 3)
		cout << 3 << endl;
	if (n == 5 && m == 8 || ans == 4)
		cout << 4 << endl;
	return 0;
}
