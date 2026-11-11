#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[200005];
int v[25];
int ans[25];
int maax = INT_MIN;

void dfs(int dep) {
	if (dep > m) {
		int sum = ans[1];

		for (int i = 1; i <= m ; i++) {

			sum = sum & ans[i];

		}

		maax = max(maax, sum);
	} else {
		for (int i = 1; i <= n; i++) {

			if (v[i] == 0) {
				v[i] = 1;
				ans[dep] = a[i];
				dfs(dep + 1);
				v[i] = 0;
			}
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int max1 = INT_MIN;
	int h;

	for (int i = 1; i <= n; i++) {

		max1 = max(max1, a[i]);
		cin >> a[i];

		if (i == 1) {
			h = a[i];
		} else {
			h &a[i];
		}
	}

	if (n <= 20) {
		dfs(0);
		cout << maax;
	} else if (m == 1) {
		cout << max1;
	} else if (m == n) {
		cout << h;
	} else if (m == 2) {
		int ymax = INT_MIN;

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				ymax = max(ymax, a[i] & a[j]);
			}
		}

		cout << ymax;
	} else {
		sort(a + 1, a + n + 1);
		int an = a[n];

		for (int i = n - 1; i >= n - m + 1; i++) {

			an = an & a[i];
		}

		cout << an;
	}

	return 0;
}