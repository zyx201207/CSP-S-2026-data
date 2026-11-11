#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, max_ = 30;
bool A;
vector<int> bucket[30], a;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bool flag = false;
		for (int j = 0; A && j < 30; j++) {
			if (a[i] == ((1ll << j) - 1)) flag = true;
		}
		A &= flag;
	}
	sort(a.begin(), a.end());
	if (m == 1 || A) {
		cout << a[n - m];
		return 0;
	}
	while (1) {
		for (int i = 0; i < max_; i++) bucket[i].clear();
		if (max_ == 0) {
			int ans = bucket[0][0];
			for (int j = 1; j < m; j++) {
				ans &= bucket[0][j];
			}
			cout << ans;
			return 0;
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < max_; j++) if (a[i] & (1ll << j)) bucket[j].push_back(a[i]);
		for (int i = max_ - 1ll; i >= 0; i--) {
			if (bucket[i].size() > m) {
				a.clear();
				for (int j = 0; j < bucket[i].size(); j++) a.push_back(bucket[i][j]);
				n = bucket[i].size();
				max_ = i;
//				for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
//				cout << '\t'; 
//				cout << max_ << '\n';
				break;
			} else if (bucket[i].size() == m) {
				int ans = bucket[i][0];
				for (int j = 1; j < m; j++) {
					ans &= bucket[i][j];
				}
				cout << ans;
				return 0;
			}
		}
		int ans = bucket[max_ - 1][0];
		for (int j = 1; j < m; j++) {
			ans &= bucket[max_ - 1][j];
		}
		cout << ans;
		return 0;
	}
	return 0;
}
