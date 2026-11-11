#include <bits/stdc++.h>
using namespace std;
//#define int long long
int a[2000050], ID, n, d, T, ans, cnt;
set<int>uni;

void dfs(int dep, int cntp, int ed) {
	if (dep > ed) {
		uni.insert(cntp);
		cnt++;
		return ;
	}
	for (int i = dep + 1; i <= ed; i++) {
		if (abs(a[i] - a[dep]) <= d)
			dfs(i, cntp + 1, ed);
	}
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> ID >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cnt = 1;
				dfs(i, 1, j);
				if (uni.size() != cnt)
					ans++;
				uni.empty();
			}
		}
		cout << ans << "\n";
	}
	return 0;

//
}
/*
priority

*/