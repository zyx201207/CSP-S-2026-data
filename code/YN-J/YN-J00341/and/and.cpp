#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int n, m;
int ans = -1;



void dfs(int step, int use, int sum) {
	if (use > m)
		return;
	if (step > n) {
		if (use == m) {
			ans = max(ans, sum);
		}
		return ;
	}
	if (sum == 0) {
		dfs(step + 1, use + 1, a[step]);
		dfs(step + 1, use, sum);
	} else {
		dfs(step + 1, use + 1, sum & a[step]);
		dfs(step + 1, use, sum);
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == n) {
		int now = a[1];
		for (int i = 2; i <= n; i++) {
			now &= a[i];
		}
		cout << now;
	} else if (m == 1) {
		int mmax = -1;
		for (int i = 1; i <= n; i++)
			mmax = max(mmax, a[i]);
		cout << mmax;
	} else if (m == 2) {
		int mmax = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j)
					mmax = max(mmax, a[i] & a[j]);
			}
		}
		cout << mmax;
	} else {
		dfs(1, 0, 0);
		cout << ans;
	}
	return 0;
}