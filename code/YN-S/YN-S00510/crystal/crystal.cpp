#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 10;
ll n, m;
ll a[N];
ll sum[N];
ll t[N];

bool check(ll mid) {
	ll cnt = 1;
	ll res = 0;
	for (ll i = 1; i < mid; i++) {
		res += cnt * a[i];
		cnt++;
	}
	cnt--;
	for (ll i = mid ; i < n; i++) {
		if (res <= m) {
			//cout << t[i] << endl;
			return true;
		}
		res -= (sum[i - 1] - sum[i - mid]) ;
		res += a[i] * cnt;
	}
	if (res <= m) {
		//cout << t[n] << endl;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);


	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> t[i];
	}
	sort(t + 1, t + n + 1);
//	for (int i = 1; i <= n; i++) {
//		cout << t[i] << " ";
//	}
	//cout << endl;
	for (ll i = 2; i <= n; i++) {
		a[i - 1] = t[i] - t[i - 1];
		//	cout << a[i - 1] << " ";
	}
	//cout << endl;
	sum[1] = a[1];
	//cout << sum[1] << " ";
	for (ll i = 2; i < n; i++) {
		sum[i] = sum[i - 1] + a[i];
		//cout << sum[i] << " ";
	}
	//cout << endl;
	ll l = 1, r = n + 1;
	while (l + 1 != r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l;

	return 0;
}
//niceeeeeeee