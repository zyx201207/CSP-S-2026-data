#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, L;
const int M = 2e5 + 5;
int ans[M], vis[M], sum[M], tmp[M], sum3[M];
int maxn = INT_MIN;
bool flag = 1, f = 0;
int pos;

void dfs(int dep, int last) {
	if (dep > L) {
		sum[0] = ans[tmp[1]];
		for (int i = 1; i <= L; i++) {
			sum[i] = (sum[i - 1] & ans[tmp[i]]);
		}
		maxn = max(maxn, sum[L]);

	}
	for (int i = last; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			tmp[dep] = i;
			dfs(dep + 1, i + 1);
			vis[i] = 0;
		}
	}
}


bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> L;

	for (int i = 1; i <= n; i++) {
		cin >> ans[i];
		int t = log2(ans[i]) + 1;
		if (ans[i] == i - 1) {
			pos++;
		}
	}
	if (n == 1) {
		int res = -1;
		for (int i = 1; i <= n; i++) {
			res = max(res, ans[i]);
		}
		cout << res;
		return 0;
	} else if (n == L) {

		int sm = ans[1];
		for (int i = 1; i <= n; i++) {
			sm &= ans[i];
		}
		cout << sm;
		return 0;
	} else if (pos == n) {
		cout << 0;
	} else {
		dfs(1, 1);
		cout << maxn;
	}


	return 0;
}
/*
5 1
31 3 1 15 7
*/
