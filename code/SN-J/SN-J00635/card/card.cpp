//梁伯温 西安辅轮中学 SN-J00635
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 5e5 + 5;

int n, m;;
vector<int> a;
vector<int> zm;
vector<long long> ans;
vector<int> id;

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int j = 1; j <= n; j ++) cin >> a[j];
	for (int i = 1; i <= n; i ++) {
		zm.clear();
		for (int j = i; j <= n; j ++) {
			int k = a[j];
			if (zm[id[k]]) {
				for (int l = id[k]; l <= n; l++) {
					zm[l] = 0;
				}
			} else {
				id[k] = j;
			}
			zm.push_back(a[j]);
		}
		for (int j = 1; j <= m; j++) {
			if (zm[j]) ans[j] ++;
		}
	}
	for (int j = 1; j <= m; j ++) cout << ans[j] << " ";
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}
