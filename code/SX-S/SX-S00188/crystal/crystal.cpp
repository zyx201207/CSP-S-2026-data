#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n + 3];
	//long long b[n + 3] = {0};
	long long dp[n + 3] = {1};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
//	for (int i = 1; i <= n; i++) {
//		b[i] = a[i] - a[i - 1];
//	}
	int j;
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = abs(dp[i - 1]) + abs(a[i]);
		//cout << dp[i] << " ";
		if (dp[i] >= m) {
			j = i;
			break;
		}

		j = i;
	}
	cout << j;





	return 0;
}
