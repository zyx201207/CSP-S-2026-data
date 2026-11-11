#include <bits/stdc++.h>
using namespace std;
vector<int> mp[35];
int a[200005];
bool v[25], chosed[200005];
bool cmp(int X, int Y) {
	int x = a[X], y = a[Y];
	for (int i = ceil(log2(x)); i >= 0; i--) {
		int xres = (x >> i) % 2;
		int yres = (y >> i) % 2;
		if (xres == 1 and yres == 0) {
			return 1;
		}
		if (xres == 0 and yres == 1) {
			return 0;
		}
	}
	return 0;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= 20; j++) {
			if ((a[i] >> (j - 1)) % 2 == 1) {
				mp[j].emplace_back(i);
			}
		}
	}
	vector<int> ans;
	for (int i = 30; i >= 1; i--) {
		if (mp[i].size() >= m and !v[i]) {
			sort(mp[i].begin(), mp[i].end(), cmp);
			int res = -1;
			for (int j = 0; j < mp[i].size(); j++) {
				if (!chosed[mp[i][j]]) {
					res = mp[i][j];
					chosed[res] = 1;
					ans.emplace_back(a[res]);
					for (int i = ceil(log2(a[res])); i >= 0; i--) {
						int t = (a[res] >> i) % 2;
						if (t == 0) v[i] = 0;
					}
					if (ans.size() == m) break;
				}
			}
			if (ans.size() == m) break;
		}
	}
	int res = ans[0];
	for (auto i : ans) {
		res = res & i;
	}
	cout << res;
	return 0;
}
//Be careful with the time
