#include <bits/stdc++.h>
using namespace std;
int a[200005];
int bl = 0, s = 0;
int n, m;

void dfs(int x, int t, int p) {
	if (t == m) {
		s = max(s, p);
		return;
	}
	if (x > n)
		return;
	if (t == 0)
		dfs(x + 1, t + 1, a[x]);
	else {
		dfs(x + 1, t + 1, p & a[x]);
	}
	dfs(x + 1, t, p);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1)
			s = a[1];
		else
			s = s & a[i];
	}
	if (n == m)
		cout << s;
	else {
		s = 0;
		dfs(1, 0, 0);
		cout << s;
	}
	return 0;
}