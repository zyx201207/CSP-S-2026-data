#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const ll N = 5e5+5;
ll a[N];
ll sum = 0, mx = -1e9, ans, ansans = -1, id = 0, num = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + 1 + n);
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << ' ';
//	}
//	cout << '\n';
	for (ll i = 1; i <= n; i++) {
		ll l = i - 1, r = i + 1, ans = 0;
		ll sy = m;
		while (sy || r - l + 1 == n) {
			bool f1 = 0, f2 = 0;
			if (l >= 1 && r <= n) {
				if (sy >= min(a[i] - a[l], a[r] - a[i])) {
					sy -= min(a[i] - a[l], a[r] - a[i]);
					if (a[i] - a[l] < a[r] - a[i]) {
						f1 = 1;
					} else {
						f2 = 1;
					}
					ans++;
				} else break;
			} else if (l >= 1) {
				if (sy >= a[i] - a[l]) {
					sy -= a[i] - a[l];
					f1 = 1;
					ans++;
				} else break;
			} else if (r <= n) {
				if (sy >= a[r] - a[i]) {
					sy -= a[r] - a[i];
					f2 = 1;
					ans++;
				} else break;
			} else {
				break;
			}
			if (f1)l--;
			if (f2)r++;
		}
		ansans = max(ans, ansans);
		if (ans == ansans)id = i;
	}
//	for (int i = 1; i <= n; i++) {
//		cout << abs(a[id] - a[i]) << ' ';
//		num += (abs(a[id] - a[i]));
//	}
//	cout << '\n' << num << '\n';
	cout << /*id << " " << a[id] <<*/ansans + 1;
	return 0;
}