#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll maxn = 2e6 + 5;
const ll INF = 1e18;

ll n, d;
ll a[maxn];
ll cur;
vector<ll> e[maxn];
ll dis[maxn], cnt[maxn];
void solve() {
	cin >> n >> d;

	for (ll i = 1; i <= n; i++) {

		e[i].clear();
		cin >> a[i];
	}

	for (ll i = 1; i <= n; i++) {

		for (ll j = 1; j <= n; j++) {

			if (i == j)
				continue;

			if (abs(a[i] - a[j]) <= d)
				e[i].push_back(j);
		}
	}

	ll ans = 0;

	for (ll st = 1; st <= n; st++) {

		queue<ll> q;
		q.push(st);

		for (ll i = 1; i <= n; i++) {

			cnt[i] = 0;
			dis[i] = INF;
		}

		dis[st] = 0;
		cnt[st] = 1;

		while (!q.empty()) {
			ll now = q.front();
			q.pop();

			for (ll nxt : e[now]) {
				if (cnt[nxt] == 0) {
					cnt[nxt] = cnt[now];
					dis[nxt] = dis[now] + 1;
					q.push(nxt);
				} else {
					if (dis[nxt] == dis[now] + 1)
						cnt[nxt]++;
				}
			}
		}

		for (ll i = 1; i <= n; i++) {

			ans += (cnt[i] == 2);
		}
	}

	cout << ans / 2 << "\n";
}

void solve1() {
	cin >> n >> d;

	for (ll i = 1; i <= n; i++)

		cin >> a[i];

	if (n <= 3) {
		cout << 0 << "\n";
		return ;
	}

	ll k = a[2] - a[1];

	if (k >= d) {
		cout << 0 << "\n";
		return ;
	}

//	cout << n << " " << k << " " << d << " " << d / k << " " <<
	cout << max(n - 1 - (d / k - 1) * 2, 0ll) << "\n";
	return ;

//	if (a[3] - a[1] <= d && a[4] - a[1] >= d) {
//		cout << n << "\n";
//	} else {
//		cout << 0 << "\n";
//	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T = 1;
	ll c;
	cin >> c;
	cin >> T;

	for (ll t = 1; t <= T; t++) {

		if (c == 11 || c == 12)
			solve1();
		else
			solve();
	}
}