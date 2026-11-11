#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];

int dp[3][20000005] = {0};

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a + 0, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[0][a[i] + j]++;
			dp[1][a[i] + j] += j;
		}
	}
	int k = a[n - 1] + m;

	int count = 0;
	for (int i = 0; i <= k; i++) {
		if (dp[0][i] >= count and dp[1][i] <= m) {
			count = dp[0][i];
		}
	}
	cout << count;

	fclose(stdin);
	fclose(stdout);
	return 0;
}