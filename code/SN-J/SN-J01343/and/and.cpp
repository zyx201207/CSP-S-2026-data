#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m, outp=-1, ans[N], a[N];
bool used[N];

void dfs(int cur) {
	if (cur == m) {
		int res = ans[0];
		for (int i = 0; i < cur-1; i++) {
			res &= ans[i+1];
		}
		outp = max(outp, res);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			ans[cur] = a[i];
			dfs(cur+1);
			used[i] = false;
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0);
	cout << outp;
	return 0;
}
