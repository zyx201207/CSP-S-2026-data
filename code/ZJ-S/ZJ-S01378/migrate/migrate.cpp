#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

const ll N = 2e6 + 5;
const ll inf = numeric_limits<ll>::max() / 100;

// Vars
ll c, t;
ll n, d, ans;

ll x[N];
unordered_map<ll, ll> min_step;
unordered_map<ll, ll> dp[N];

void init() {
	ans = 0;
	for (ll i = 1; i <= n; i++) {
		x[i] = 0;
	}
}

ll get_length(ll ind) {
	return x[ind + 1] - x[ind];
}
void dfs(ll now, ll step) {
	if (step > min_step[now]) return;
	min_step[now] = step;
	dp[now][step]++;

	ll now_cost = get_length(now);
	for (ll i = now + 1; i <= n; i++) {
		if (now_cost > d) break;
		dfs(i, step + 1);
		now_cost += get_length(i);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while (t--) {
		init(); // 清理掉过去的产物

		cin >> n >> d;
		for (ll i = 1; i <= n; i++) {
			cin >> x[i];
		}

		for (ll st = 1; st <= n; st++) { // 枚举起点
			min_step.clear();
			for (ll i = 1; i <= n; i++) {
				dp[i].clear();
				min_step[i] = n + 1;
			}

			dfs(st, 0);
			for (ll ed = st + 1; ed <= n; ed++) {
				if (dp[ed][min_step[ed]] != 0) {
					if (dp[ed][min_step[ed]] == 2) ans++;
				}
			}

			// DEBUG
			// cout << "**" << st << ": " << endl;
			// for (ll ed = st + 1; ed <= n; ed++) {
			// 	cout << ed << ": " << min_step[ed] << " -> " << dp[ed][min_step[ed]] << endl;
			// }
		}

		// DEBUG
		// cout << "**ANS: ";
		cout << ans << "\n";
	}
	fflush(stdout);

	return 0;
}
