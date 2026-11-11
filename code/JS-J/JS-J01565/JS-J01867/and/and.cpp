#include <bits/stdc++.h>
using namespace std;

int n, m, maxn;
int a[300005];
bool vis[300005];

int dfs(int cnt, int ans) {
	if(cnt == m + 1) return max(maxn, ans);
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			dfs(cnt + 1, ans & a[i]);
			vis[i] = 0;
			dfs(cnt, ans);
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << dfs(0, a[1]);
	return 0;
}
