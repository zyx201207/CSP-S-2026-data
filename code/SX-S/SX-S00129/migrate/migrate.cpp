#include <bits/stdc++.h>

using namespace std;

int a[1000005], dp[1000005], di[1000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, i, j, k;
		cin >> n >> d;
		for (i = 1; i <= n; i++) {
			cin >> a[i];
			di[i] = 0;
		}
		di[1] = 1;
		for (i = 2; i <= n; i++)
			for (j = 1; j < i; j++)
				if (a[i] - a[j] <= d)
					di[i] += di[j];
		int sum = 0;
		for (i = 1; i <= n; i++) {
			for (k = 2; k < i; k++)
				dp[i] += di[k];
			if (dp[i] == 2)
				sum++;
		}

		cout << sum << "\n";
	}
	return 0;
}
