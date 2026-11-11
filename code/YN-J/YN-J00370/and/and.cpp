#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans, bj[200005];

void dfs(int num, int sum) {
	if (num == m) {
		ans = max(ans, sum);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (bj[i] == 0) {
			bj[i] = 1;
			dfs(num + 1, sum & a[i]);
			bj[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(0, 16777215);
	cout << ans;
	return 0;
}