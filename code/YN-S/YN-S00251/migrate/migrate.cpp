#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t, ans = 0;
ll a[2000006], dis[2000005], team[2000005];

int main() {
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ll n, s;
		memset(team, 0, sizeof(team));
		cin >> n >> s;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dis[1] = 0;
		for (ll i = 2; i <= n; i++) {
			dis[i] = abs(a[i] - a[i - 1]);
		}
		ll cur = 1, tot = s, cnt = 0;
		for (ll i = 1; i <= n; i++) {
			if (dis[i] > s)
				break;
			tot -= dis[i];
			if (tot > 0)
				cnt++;
			else if (tot == 0) {
				cnt++;
				team[cur] = cnt - 1;
				cur++;
				cnt = 0;
				tot = s;
			} else if (tot < 0) {
				team[cur] = cnt - 1;
				cur++;
				cnt = 0;
				tot = s;
			}
			for (ll i = 1; i < cur; i++) {
				if (team[i] == 2)
					ans++;
			}
		}
		if (ans - 1 < 0)
			cout << 0 << '\n';
		else
			cout << ans - 1 << '\n';
		ans = 0;
	}
	return 0;
}