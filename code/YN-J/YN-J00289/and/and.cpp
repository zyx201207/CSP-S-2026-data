#include <bits/stdc++.h>
using namespace std;
int n, m, maxx = 0, maxn = 0;
int dp[200010], A[200010], Z[10], ans = 0, B[2000210][0];

void dfs(int x, int num) {
//	cout << x << ' ' << num << '\n';

	if (x > min(m, 4)) {
		ans = max(ans, num);
		return;
	}

	for (int i = 1; i <= 4; i++) {

		if (Z[i] == 0)
			continue;
//		cout << "///" << i << ' ' << (i & num) << '\n';
		Z[i]--;
		dfs(x + 1, num & i);
		Z[i]++;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	B[0][0] = INT_MAX;
	B[n + 1][1] = INT_MAX;
	//cout << B[0][0] << ' ' << B[n + 1][1];

	for (int i = 1; i <= n; i++) {

		B[0][0] = INT_MAX;
		B[n + 1][1] = INT_MAX;
		cin >> A[i];
		B[i][0] = B[i - 1][0] & A[i];

		//	cout << i << ' ' << B[0][0] << ' ' << B[i][0];

		if (A[i] > maxx) {
			maxx = max(maxx, A[i]);
		} else if (A[i] > maxn) {
			maxn = max(maxn, A[i]);
		}

		if (A[i] <= 4) {
			Z[A[i]]++;
		}
	}



	for (int i = n; i >= 1; i--) {

		B[0][0] = INT_MAX;
		B[n + 1][1] = INT_MAX;
		B[i][1] = B[i + 1][1] & A[i];
	}


//	cout << maxx << ' ' << maxn << '\n';

	if (n <= 2000) {
		dp[0] = INT_MAX;

		for (int i = 1; i <= n; i++) {

			for (int j = min(i, m); j >= 1; j--) {

				dp[j] = max(dp[j - 1] & A[i], dp[j]);
			}
		}

		cout << dp[m];
	} else {


		if (maxx <= 4) {
			dfs(1, INT_MAX);
			cout << ans;
		} else {
			if (m == n - 1) {
				for (int i = 1; i <= n; i++) {

					//		cout << B[i - 1][0] << ' ' << B[i + 1][1] << '\n';
					ans = max(ans, B[i - 1][0] & B[i + 1][1]);
				}

				cout << ans;
			} else {
				cout << maxx;
			}

		}

	}

	return 0;
}
