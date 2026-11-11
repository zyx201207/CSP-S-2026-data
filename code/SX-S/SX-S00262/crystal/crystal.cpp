#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e5+10;

ll n, m;
ll arr[N];
ll ans;

void ans1() {
	ll sum = 0, ans = 0;
	for (ll i = 1; i <= n; i++) {
		sum += i;
		if (sum > m) {
			if (i > 1)
				cout << i;
			else
				cout << 0;
			return ;
		}
		ans = i;
	}
	cout << ans;
}

ll brr[N];

void ans2() {
	ll a = arr[2] - arr[1];
	ll sum = 0, ans = 0;
	for (ll i = 1; i <= n; i++) {
		sum += i * a;
		if (sum > m) {
			if (i > 1)
				cout << i;
			else
				cout << 0;
			return ;
		}
		ans = i;
	}
	cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	bool f = 0;
	bool f2 = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] != i) {
			f = 1;
		}
	}

	for (ll i = 1; i <= n; i++) {
		if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2] && i > 2) {
			f2 = 1;
		}
	}

	if (!f) {
		ans1();
		return 0;
	}
	if (!f2) {
		ans2();
		return 0;
	}

	sort(arr + 1, arr + n + 1);

	for (ll i = 2; i <= n; i++) {
		brr[i - 1] = arr[i] - arr[i - 1];
	}

	ll id = 1;
	for (ll j = id; j < n; j++) {
		ll sum = 0;
		ll m2 = m;

		for (ll i = j; i < n; i++) {
			sum++;
			m2 -= brr[i] * sum;
			if (m2 < 0) {
				id = i - 1;
				break;
			}

			//cout << ans << endl;
		}
		ans = max(ans, sum);
	}

	cout << ans;
	return 0;
}
