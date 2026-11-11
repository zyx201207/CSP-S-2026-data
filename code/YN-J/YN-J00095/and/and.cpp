#include <bits/stdc++.h>
using namespace std;
long long a[200001];
int n, m;
int ans = 0;

void dfs(int pos, int cnt, int sum) {
	if (cnt == m) {
		ans = max(ans, sum);
		return;
	}
	if (pos == n + 1) {
		return;
	}
	if (cnt > m) {
		return;
	}
	dfs(pos + 1, cnt + 1, a[pos] & sum);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 1);
	cout << ans;
	return 0;
}
