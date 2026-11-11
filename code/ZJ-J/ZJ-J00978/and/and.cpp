#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5;
int a[N + 1];
int maxx = 0;
void dfs(int x, int sum, int k) {
	if (k == m) {
		if (sum == INT_MAX) return;
		maxx = max(maxx, sum);
		return;
	}
	if (x == n)
		return;
	dfs(x + 1, sum & a[x + 1], k + 1);
	dfs(x + 1, sum, k);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, INT_MAX, 0);
	cout << maxx << endl;
	return 0;
}
