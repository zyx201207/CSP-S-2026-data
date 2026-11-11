#include <bits/stdc++.h>
using namespace std;


int c, t;

inline void func() {
	int n, d;
	long long x[5005], res = 0;
	int dp[5005];
	cin >> n >> d;

	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = i + 1; j <= n; j++) {
			dp[j] = 2000005;
			if (x[j] - x[i] <= d) {
				dp[j] = 1;
				continue;
			}
			int maxequ = 0;
			for (int k = j - 1; x[j] - x[k] <= d; k--) {
				if (dp[k] + 1 < dp[j]) {
					dp[j] = dp[k] + 1;
					maxequ = 1;
				} else if (dp[k] + 1 == dp[j]) {
					maxequ++;
				}
			}
			if (maxequ == 2)
				res++;
		}
	}

	cout << res << endl;
}


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;

	if (c <= 2) {
		for (int _ = 0; _ < t; _++) {
			func();
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
