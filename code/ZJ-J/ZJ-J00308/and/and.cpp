#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], sum[N];
int n, m, ans;

void dfs(int i, int x, int cnt) {
	if (x == m) {
		ans = max(ans, cnt);
		return ;
	}
	if (i == n) {
		return ;
	}
	if (x == 0) {
		dfs(i + 1, 1, a[i]);
		dfs(i + 1, 0, 0);
	}
	dfs(i + 1, x + 1, cnt & a[i]);
	dfs(i + 1, x, cnt);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] & a[i];
	}
	if (n <= 20) {
		dfs(1, 0, 0);
		cout << ans;
		return 0;
	} 
	if (n <= 2000) {
		if (m == 1) {
			int mx = 0;
			for (int i = 1; i <= n; i++) {
				mx = max(mx, a[i]);
			}
			cout << mx;
		}
		if (m == n) {
			cout << sum[n];
		}
		if (m == 2) {
			int mx = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					int sum = a[i] & a[j];
					mx = max(mx, sum);
				}
			}
			cout << mx;
		}
		return 0;
	}
	return 0;
}

/*
4 2
3 15 12 12
*/

/*
5 3
31 3 1 15 7
*/