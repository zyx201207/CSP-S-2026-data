#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int m, n, arr[N], d[N][50];
unordered_set<int> to;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		for (int k = 0; k <= 40; ++k) {
			if ((arr[i] >> (40 - k)) & 1) {
				d[i][k] = 1;
			}
		}
		to.insert(i);
	}

	for (int i = 0; i <= 40; ++i) {
		bool ok = 0;
		int cnt = 0;
		for (const auto& k : to) {
			if (d[k][i]) ++cnt;
			if (cnt >= m) {
				ok = 1;
				break;
			}
		}
		
		if (ok) {
			vector<int> to_erase;
			for (const auto& k : to) {
				if (!d[k][i]) {
					to_erase.push_back(k);
				}
			}
			
			for (const auto& k : to_erase) {
				to.erase(k);
			}
		}
	}
	
	if (to.size() < m) {
		cout << 0;
		return 0;
	}
	int ans = LLONG_MAX;
	for (const auto& k : to) {
		ans &= arr[k];
	}
	
	cout << ans;

	return 0;
}
