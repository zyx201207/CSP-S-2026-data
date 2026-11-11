#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 10;
int c, t;
int n, d, x[N];
ll cnt[N];
bool vis[N], ok[N];
void dfs (int u) {
	for (int i = 1; i <= n; i++) {
		if (i == u)
			continue;
		if (abs(x[u] - x[i]) <= d && vis[i] == false) {
			cnt[i]++;
			if (cnt[i] > 2)
				ok[i] = true;
			vis[i] = true;
			dfs(i);
		}
	}
}

int main () {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				vis[j] = false;
			dfs(i);
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 2) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
