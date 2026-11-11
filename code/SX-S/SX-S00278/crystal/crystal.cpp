#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1200000], s[1200000], loca[1200000];
ll cnt, n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	s[0] = 0;
	ll mx = 0;
	int flag = 1, ppo = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i >= 3 && flag == 1) {
			if ((a[i] - a[i - 1]) != (a[i - 1] - a[i - 2])) {
				flag = 0;
			}
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (a[i] != a[i - 1]) {
			loca[++ppo] = i;
		}
		s[i] = s[i - 1] + a[i];
	}

	if (flag == 0) {
		for (ll i = 1; i <= ppo; ++i) {
			for (int j = 1; j < loca[i]; ++j) {
				cnt = a[loca[i]] * (loca[i] - j + 1 ) - (s[loca[i]] - s[j - 1]);
				if (m >= cnt) {
					mx = max(mx, loca[i + 1] - j);
				}
			}
		}
	} else if (flag == 1) {
		for (ll i = 1; i <= n; ++i) {
			cnt = a[i] * i - s[i];
			if (m >= cnt) {
				mx = max(mx, i);
			}
		}
	}
	cout << mx;
	return 0;
}
