#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int ans = -1;
bool vis[N];
int a[N], n, m;

void dfs(int sum, int cnt) {
	if (cnt == m + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == true) {
			continue;
		} else {
			vis[i] = true;
			dfs(sum & a[i], cnt + 1);
			vis[i] = false;
		}
	}
}

int main() {
	freopen("ans.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(a[i], 1);
	}
	cout << ans;
	return 0;
}