#include <bits/stdc++.h>
using namespace std;
int a[500050], ans[300050], lst[300050];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++ i) {
		vector<int> v;
		for (int j = i; j <= n; ++ j) {
			if (lst[a[j]] != 0) {
				int u = lst[a[j]];
				for (int k = v.size(); k >= u && !v.empty(); -- k) {
					lst[v[k - 1]] = 0;
					v.pop_back();
				}
			}
			v.push_back(a[j]);
			lst[a[j]] = v.size();
		}
		int l = v.size();
		for (int j = 1; j <= l; ++ j) {
			ans[v[j - 1]] ++;
			lst[v[j - 1]] = 0;
		}
	}
	for (int i = 1; i <= m; ++ i) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}