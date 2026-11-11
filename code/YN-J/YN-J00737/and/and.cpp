#include <bits/stdc++.h>
using namespace std;
int n, m, a1[200002], ans, ans1, ans2, ans3;

void dfs(int dep, int sum, int cnt) {
	if (dep > n) {
		if (cnt == m)
			ans = max(ans, sum);
		return ;
	} else {
		if (cnt < m) {
			int p = sum & a1[dep];
			dfs(dep + 1, p, cnt + 1);
		}
		dfs(dep + 1, sum, cnt);
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> a1[1];
	ans1 = a1[1];
	ans2 = a1[1];
	for (int i = 2; i <= n; i++) {
		cin >> a1[i];
		ans1 &= a1[i];
		ans2 = max(ans2, a1[i]);
	}
	if (n == m) {
		cout << ans1;
		return 0;
	} else if (m == 1) {
		cout << ans2;
		return 0;
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans3 = max(ans3, a1[i] & a1[j]);
			}
		}
		cout << ans3;
		return 0;
	}
//	if(m==n-1){
//		for(int i=1;i<=n;i++){
//
//		}
//	}
	dfs(1, pow(2, 20) - 1, 0);
	cout << ans;
	return 0;
}