#include <bits/stdc++.h>
using namespace std;

struct man {
	long long a, t;
};
long long ans = -1e18;
long long c, n, m, d, q;
long long w[200005];
long long k[200005];
vector<long long> a[200005];
vector<long long> t[200005];

void dfs(long long x, long long cnt, long long y) {
	for (int i = 1; i <= n; i++) {
		bool man = 0;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] == y) {
				ans = min(ans, cnt + w[a[i][j]]);
				return;
			}
			if (a[i][j] == x)
				man = 1;
			if (man)
				dfs(a[i][j], cnt + t[i][j] * 2, y);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			long long a1, t1;
			cin >> a1 >> t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
		}
	}
	while (q--) {
		long long x, y;
		cin >> x >> y;
		dfs(x, w[x], y);
		cout << ans << "\n";
		ans = -1e18;
	}
	return 0;
}