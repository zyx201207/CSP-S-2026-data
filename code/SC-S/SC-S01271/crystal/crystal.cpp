#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n, m, a[N];
ll d[N];
ll ans = -1;
bool check(ll mid, ll dif) {
	if ((mid * mid + mid) / 2 * dif < m)
		return 1;
	else return 0;
}
ll binary(ll dif) {
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid, dif))
			l = mid + 1;
		else r = mid;
		if (l == r) return l;
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll flag = 1;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			flag = 0;
	}
	if (flag) {
		ll dif = a[2] - a[1];
		cout << binary(dif);
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[j] = a[i] - a[j];
		}
		ll mm = m;
		ll cnt = 0;
		for (int j = i; j >= 1; j--) {
			if (d[j] <= mm) {
				cnt++;
				mm -= d[j];
			} else break;
			if (mm <= 0) break;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}