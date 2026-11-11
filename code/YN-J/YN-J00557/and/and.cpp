#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = -4e18;
int n, m;
int a[200005];
int b[200005];
int ans = inf;

bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == 1) {
			cnt ++;
		}
	}
	if (cnt == m) {
		return true;
	}
	return false;
}

int check1() {
	int ans1, t = 1;
	for (int i = 1; i <= n; i++) {
		if (b[i] == 1) {
			if (t == 1) {
				ans1 = a[i];
				t = 0;
			} else {
				ans1 &= a[i];
			}
		}
	}
	return ans1;
}

void dfs(int x) {
	if (x > n) {
		if (check()) {
			ans = max(ans, check1());
		}
		return ;
	}
	b[x] = 1;
	dfs(x + 1);
	b[x] = 0;
	dfs(x + 1);
}

bool cmp(int l, int r) {
	return l > r;
}

signed main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 20) {
		dfs(1);
		cout << ans;
		return 0;
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	if (m == n) {
		int ans2, t1 = 1;
		for (int i = 1; i <= n; i++) {
			if (t1 == 1) {
				ans2 = a[i];
				t1 = 0;
			} else {
				ans2 &= a[i];
			}
		}
		cout << ans2;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[m];
	return 0;
}