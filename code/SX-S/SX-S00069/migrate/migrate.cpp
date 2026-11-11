#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+5;
ll n, m, a[N], c, t[N], T, ans;

void dfs(ll x, ll w) {
	for (int j = w; j <= n; j++) {
		if (a[w] - a[x] <= m) {
			t[w]++;
			dfs(a[w], j + 1);
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			dfs(a[i], i + 1);
			for (int k = 2; k <= n; k++) {
				if (t[k] == 2)
					ans++;
				t[k] = 0;
			}

		}

		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

*/