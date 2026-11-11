#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e6+10;

ll c, t;
ll n, m;
ll arr[N];

void ans1() {
	ll ans = 0;
	ll a = arr[2] - arr[1];
	if (m < a * 2) {
		cout << 0 << endl;
		return ;
	}
	ll cnt;
	if (m % a == 0)
		cnt = m;
	else
		cnt = m - m % a;
//	cout << a << " " << cnt << endl;
	for (ll j = 1; j + 3 <= n; j++) {
		for (ll i = j + 3; i <= n; i++) {
			if ((arr[i] - arr[j]) % cnt == 0) {
				continue;
			}
			if ((arr[i] - arr[j]) / cnt + 1 > 3) {
				break;
			}
			ans++;
		}
	}
	cout << ans;
}

ll xrr[N];

void dfs(ll x, ll y, ll step) {
	for (ll i = x + 1; i <= y; i++) {
		if (arr[i] - arr[x] <= m) {
			//	cout << step << endl;
			dfs(i, y, step + 1 );
			//step--;
		}
	}
	if (x == y)
		xrr[step]++;
//	cout << step << endl;
	return ;
}

void ans2() {
	ll ans = 0;
	for (ll j = 1; j + 3 <= n; j++) {
		for (ll i = j + 3; i <= n; i++) {
			dfs(j, i, 0);
			for (ll k = 1; k <= n; k++) {
				//	cout << k << "a" << xrr[k] << " ";
				if (xrr[k]) {
					if (xrr[k] == 2) {
						ans++;
					}
					break;
				}
			}
			//	cout << endl;
			memset(xrr, 0, sizeof(xrr));
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;

		bool f = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (ll i = 1; i <= n; i++) {
			if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2] && i > 2) {
				f = 1;
			}
		}
		if (n <= 9)
			ans2();
		else
			ans1();
	}
	return 0;
}
