#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x;
int a[200005];
int max1 = INT_MIN;

bool cmp(int a, int b) {
	if (a < b)
		return 0;
	else
		return 1;
}

void dfs(int dep, int sum, int awy) {
	if (dep > n ) {
		if (sum == x && awy > max1) {
			max1 = awy;
		}
	} else {
		dfs(dep + 1, sum, awy);
		if (dep + 1 <= n ) {
			dfs(dep + 1, sum + 1, awy & a[dep]);
		}

	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		dfs(i, 0, a[i]);
	}

	cout << max1;
	return 0;
}