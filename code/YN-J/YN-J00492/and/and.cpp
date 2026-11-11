//by ymxzz11 2023.10.31
//and(±©Á¦)
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, ans;
int minn = INT_MAX;
int a[N];
int A[N], B[N];

void dfs(int x) {
	if (x > m) {
		int an = A[1];
		for (int i = 1; i <= m; i++) {
			an = an & A[i];
		}
		ans = max(ans, an);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (B[i])
			continue;
		B[i] = 1;
		A[x] = a[i];
		dfs(x + 1);
		B[i] = 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	if (m == n) {
		cout << minn;
		return 0;
	}
	dfs(1);
	cout << (int)ans;
	return 0;
}