#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 10;
ll n, ans = 0;
ll cnt[N];
char c[N];
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> cnt[i] >> c[i];
	}
	ll l = 1, r = n;
	while (l < r) {
		if (c[l] == c[r]) {
			if (cnt[l] < cnt[r]) {
				cnt[r] -= cnt[l];
				cnt[l] = 0;
				l++;
			} else if (cnt[l] > cnt[r]) {
				cnt[l] -= cnt[r];
				cnt[r] = 0;
				r--;
			} else {
				cnt[l] = cnt[r] = 0;
				l++, r--;
			}
		} else {
			if (cnt[l] < cnt[r]) {
				cnt[r] -= cnt[l];
				ans += cnt[l];
				cnt[l] = 0;
				l++;
			} else if (cnt[l] > cnt[r]) {
				cnt[l] -= cnt[r];
				ans += cnt[r];
				cnt[r] = 0;
				r--;
			} else {
				ans += cnt[l];
				cnt[l] = cnt[r] = 0;
				l++, r--;
			}
		}
	}
	cout << ans;
	return 0;
}
