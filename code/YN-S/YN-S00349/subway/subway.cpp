#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
ll c, n, m, d, q;
ll t[N], cnt[N];
vector<pair<int, int> >e[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			cnt[x]++;
			e[i].push_back({x, y});
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		ll lz = INT_MAX;
		cin >> x >> y;
		for (int i = 1; i <= n; i++) {
			int flag1 = 0, flag2 = 0, sj1, sj2, jl1, jl2;
			for (auto it : e[i]) {
				int pd = it.first;
				int sj = it.second;
				if (pd == x) {
					flag1 = 1;
					sj1 = sj;
				}
				if (pd == y) {
					flag2 = 1;
					sj2 = sj;
				}
				if (cnt[pd] >= 2)
					jl1 = sj;
			}
			if (flag1 == 1 && flag2 == 1) {
				ll ans = sj1 + sj2 + t[x] + t[y];
				lz = min(ans, lz);
			} else if (flag1 == 1) {
				ll ans = sj1 + t[x] + t[y];
				for (int j = 1; j <= n; j++) {
					if (j != i) {
						for (auto it : e[j]) {
							int pd = it.first;
							int sj = it.second;
							if (pd == y) {
								flag2 = 1;
								sj2 = sj;
							}
							if (cnt[pd] >= 2)
								jl2 = sj;
						}
						lz = min(lz, ans + jl1 + jl2 + sj2);
					}
				}
			}
		}
		cout << lz << "\n";
	}


	return 0;
}