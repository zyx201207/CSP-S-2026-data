//by.pcx
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int n, m, vis[N];
long long ans;

void f(int x, long long sum) {
	if (x == m + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			f(x + 1, sum & a[i]);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 2000) {
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			vis[i] = 1;
			f(2, a[i] * 1ll);
		}
		cout << ans;
	} else {
		sort(a + 1, a + n + 1, greater<int>());
		cout << a[m];
	}
	return 0;
}