#include <bits/stdc++.h>
#define MAX_INDEX 200005
typedef long long ll;
using namespace std;
ll a[MAX_INDEX];
ll k[MAX_INDEX];
bool vis[MAX_INDEX];
int n, m;
ll maxn = -1;
ll yu(ll arr[]) {
	ll res = arr[1];
	for (int i = 2; i <= m; i++) {
		
		res = res & arr[i];
	}
	return res;
}
void dfs (int step) {
	if (step == m + 1) {
		maxn = max(maxn, yu(k));
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		k[step] = a[i];
		dfs (step + 1);
		vis[i] = 0;
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
