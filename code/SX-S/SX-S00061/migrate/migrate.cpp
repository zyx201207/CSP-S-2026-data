#include <bits/stdc++.h>
using namespace std;
int c, t;
int a[200006];
int dp[20006][20006];
int d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t > 0) {
		int n;
		cin >> n;
		cin >> d;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 1; j < i; j++) {
				if (i != j && a[i] - a[j] <= d) {
					dp[i][j] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j =  1; j <= n; j++) {
				for (int k = i + 1; k < j; k++) {
					dp[i][j] += (dp[i][k] * dp[k][j]);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] == 2) {
					cnt++;
				}
			}
		}
		cout << cnt  << endl;
		t--;
	}
	return 0;
}