#include <bits/stdc++.h>
using namespace std;
int n, m, a[200000], maxx;
bool flag;
void dfs(int u, int v, int t) {
	if(t == m) {
		maxx = max(maxx, v);
		return;
	}
	if(u == n+1) return;
	if(t < m-n+u) return;
	dfs(u+1, v, t);
	if(flag) dfs(u+1, v&a[u], t+1);
	else {
		flag = 1;
		dfs(u+1, a[u], t+1);
		flag = 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(m == n) {
		for(int i = 1; i <= n; i++) {
			maxx = (maxx&a[i]);
		}
	} else if(n > 20){
		sort(a+1,a+n+1);
		maxx = a[1];
		for(int i = 1; i <= m; i++) {
			maxx = (maxx & a[i]);
		}
	} else {
		dfs(1, 0, 0);
	}
	cout << maxx;
	return 0;
}
