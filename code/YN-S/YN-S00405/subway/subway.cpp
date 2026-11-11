#include <bits/stdc++.h>
using namespace std;
//#define int long long
int a[500050], bj[505][505], st, ed, ID, n, m, d, T, ans;



queue<int> q;
vector< pair<int, int> >esta[500050],//下标车站号first轨道号 second车站轨道时间
        esub[505];//下标轨道号1first轨道号2 second轨道换乘时间
void dfs(int dep, int sum) {
	if (bj[dep][ed]) {
		ans = min(ans, sum);
		return ;
	}
	for (auto it : esub[dep])
		dfs(it.first, sum + it.second);
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> ID >> n >> m >> d >> T;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		for (int j = 1; j <= p; j++) {
			int x, y;
			cin >> x >> y;
			bj[i][y] = 1;
			esta[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= m; i++) {
		if (esta[i].size() > 1) {
			for (int j = 0; j < esta[i].size(); j++) {
				for (int k = j + 1; k < esta[i].size(); k++) {
					esub[esta[i][j].first].push_back
					({esta[i][k].first, esta[i][j].second + esta[i][k].second});
					esub[esta[i][k].first].push_back
					({esta[i][j].first, esta[i][j].second + esta[i][k].second});
				}
			}
		}
	}
	while (T--) {
		int flag = 0;
		cin >> st >> ed;
		ans = 1e9;
		for (int i = 1; i <= n; i++) {
			if (bj[i][st] && bj[i][ed]) {
				cout << a[st] + a[ed] << "\n";
				flag = 1;
				break;
			}
		}
		if (!flag) {
			for (auto it : esta[st])
				dfs(it.first, a[st] + a[ed]);
			cout << ans << "\n";
		}
	}
	return 0;

//
}
/*
priority

*/