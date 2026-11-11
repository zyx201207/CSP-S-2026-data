#include <bits/stdc++.h>
using namespace std;

int a[200005];
int dp[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			dp[j] = a[j] ^ a[j - 1];
			ans = max(ans, dp[j]);
		}
	}

	cout << ans;


	fclose(stdin);
	fclose(stdout);
	return 0;
}