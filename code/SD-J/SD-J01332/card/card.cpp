#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<int> cnt(m + 1);
	vector<int> ans(m + 1);
	for (int i = 1; i <= n; ++i) {
		vector<bool> visited(n + 1);
		for (int j = i; j <= n; ++j) {
			if (cnt[a[j]] != 0) {
				int idx = cnt[a[j]];
				for (; idx <= j; ++idx) {
					ans[a[idx]]--;
					cnt[a[idx]] = 0;
				}
			}
			cnt[a[j]] = j;
			ans[a[j]]++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	cout <<'\n';
	return 0;
}
