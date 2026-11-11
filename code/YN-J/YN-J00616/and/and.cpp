#include <bits/stdc++.h>
using namespace std;
int a[500005], n, m, ans;
bool vis[500005];

void dfs(int cnt, int sum) {
	if (cnt == m + 1) {
		ans = max(ans, sum);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (i != cnt && !vis[i]) {
			vis[i] = true;
			dfs(cnt + 1, sum & a[i]);
			vis[i] = false;
		}
	}
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	for (int i = 1; i <= n; i++)
		dfs(1, a[i]);
	cout << ans;
	return 0;
}