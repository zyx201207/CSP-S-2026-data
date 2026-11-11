#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int a[n + 10];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if ((a[n - 1] - a[0]) / (a[1] - a[0]) == n - 1 && (a[1] - a[0]) == (a[n - 1] - a[n - 2])
	        && (a[1] - a[0]) == (a[2] - a[1]) ) {
		int zs = 0;
		for (int i = 1; i < n; i++) {
			zs += i * (a[1] - a[0]);
			if (zs > m) {
				cout << i  << endl;
				return 0;
			}
		}
	}
	long long dp[n + 10][n + 10];
	for (int i = 0; i < n; i++) {
		dp[i][i] = a[i];
	}
	int maxx = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] - a[i] > m) {
				break;
			}
			dp[i][j] = dp[i][j - 1] + a[j];
			if ((dp[i][j]  + m) % a[j] == 0) {
				maxx = max(maxx, j - i + 1);
			}
		}
	}
	cout << maxx << endl;
	return 0;
}
