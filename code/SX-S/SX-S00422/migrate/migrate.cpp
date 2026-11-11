#include <bits/stdc++.h>
using namespace std;
int const N = 2e6+10;
long long a[N], d, minx = LLONG_MAX, flg = 0;
map<long long, int>mp;
map<long long, long long>ma;

void dfs(long long q, long long z, long long s) {
	if (q == z) {
		minx = min(s, minx);
		ma[s]++;
		return;
	}
	for (long long i = d; i >= 1; i--) {
		if (mp[q + i] && q + i <= z) {
			dfs(q + i, z, s + 1);
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, T, n, ans = 0;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		mp.clear();
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			mp[a[i]] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {

				dfs(a[i], a[j], 0);
				if (ma[minx] == 2) {
					ans++;
				}
				ma.clear();
				minx = LLONG_MAX;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}