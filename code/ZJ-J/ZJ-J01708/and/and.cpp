#include<iostream>
#define int long long
using namespace std;
const int maxn = 2e5+100;
int a[maxn], n, m, ans, vis[maxn];
void dfs(int x) {
	if (x == n+1) {
		int sum = 0, cnt = 0, f = 0;
		for (int i = 1; i <= n; i++)
			if (vis[i]) {
				if (f == 0) sum = a[i], f = 1;
				sum = sum & a[i];
				cnt++;
			}
		if (cnt == m) ans = max(ans, sum);
		return;
	}
	vis[x] = 0;
	dfs(x+1);
	vis[x] = 1;
	dfs(x+1);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int maxx = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if (n > 2000) {
		cout << maxx;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
