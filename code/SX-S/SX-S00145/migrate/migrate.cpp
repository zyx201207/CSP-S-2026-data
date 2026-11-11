#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt, mm, v[15], a[15];
vector<ll> vt[15];

void dfs(int step, int u, int t) {
	if (u == t) {
		if (mm > step)
			mm = step, cnt = 1;
		else if (mm == step)
			cnt++;
		return ;
	}
	for (int w : vt[u]) {
		if (v[w] == 0) {
			v[w] = 1;
			dfs(step + 1, w, t);
			v[w] = 0;
		}
	}
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll T;
	cin >> T;
	cin >> T;
	while (T--) {

		int n, k, ans = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (abs(a[i] - a[j]) <= k)
					vt[i].push_back(j), vt[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				mm = 1e18, cnt = 0;
				v[i] = 1;
				dfs(1, i, j);
				memset(v, 0, sizeof(v));
				if (cnt == 2)
					ans++;
			}
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; i++)
			vt[i].clear();
	}
	return 0;
}
