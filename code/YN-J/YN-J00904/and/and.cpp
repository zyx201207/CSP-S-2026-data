#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int n, m;
ll a[MAXN];
bool bj[MAXN];
int ans = 0;

void dfs(int sum, int cnt) {
	if (cnt == m + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = cnt; i <= n; i++) {
		if (bj[i] == 1)
			continue;
		bj[i] = 1;
		dfs(sum & a[i], cnt + 1);
		bj[i] = 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		sort(a + 1, a + 1 + n, greater<ll>());
		cout << a[1];
		return 0;
	}
	if (n <= 500) {
		for (int i = 1; i <= n; i++) {
			dfs(a[i], 1);
		}
		cout << ans;
	} else {
		sort(a + 1, a + 1 + n);
		cout << a[m];
	}
	return 0;
}