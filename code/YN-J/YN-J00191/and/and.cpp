#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;

int a[N], t[N] = {};
unsigned long long ans = 0;

void dfs(int dep, unsigned long long he) {
	if (dep > m) {
		ans = max(ans, he);
	}
	for (int i = 1; i <= n; i++) {
		if (t[i]) {
			continue;
		}
		t[i] = 1;
		dfs(dep + 1, he & a[i]);
		t[i] = 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, INT_MAX);
	cout << ans;
	return 0;
}