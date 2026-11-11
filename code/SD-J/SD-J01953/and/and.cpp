#include <bits/stdc++.h>
using namespace std;
int maxn = -100000;
int n, m;
int a[200010];
void dfs (int idx, int id, int sum) {
	if (id == m) {
		maxn = max(sum, maxn);
		return ;
	}
	if (idx >= n || id >= m) return ;
	if (sum == -1) {
		dfs(idx + 1, id + 1, a[idx]);
	} else {
		dfs(idx + 1, id + 1, sum & a[idx]);
	}
	dfs(idx + 1, id, sum);
	
}
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxx = -1000;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			maxx = max(a[i], maxx);
		}
		cout << maxx;
	} else if (m == n) {
		maxx = a[0];
		for (int i = 1; i < n; i++) {
			maxx = maxx & a[i];
		}
		cout << maxx;
	} else if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				maxx = max(a[i] & a[j], maxx);
			}
		}
		cout << maxx;
	} else if (n <= 2000) {
		dfs(0, 0, -1);
		cout << maxn;
	} else {
		for (int i = 0; i < n; i++) {
			maxx = max(a[i], maxx);
		}
		cout << maxx;
	}
	return 0;
}
