#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005], zd = 0;
ll panduan (ll x, ll p) {
	ll left = 1, right = a[p];
	ll mid = (left + right) / 2;
	// mid 为下标，二分下标
	while (true) {
		if (a[mid] == x) {
			return mid;
		}
		else {
			if (a[mid] < x) {
				if (a[mid + 1] > x) {
					return -1;
				}
				else {
					left = mid + 1;
					mid = (left + right) / 2;
				}
			}
			else {
				if (a[mid - 1] < x) {
					return -1;
				}
				else {
					right = mid - 1;
					mid = (left + right) / 2;
				}
			}
		}
	}
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ll n, m; cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	// 对于每个a[i]，向前尽可能走，遇到新的就将走的速度*2，计算走完之后走过的水晶数字个数，最大即为所求
	for (ll i = 1; i <= n - 1; i++) {
		if (a[i + 1] - a[i] > m) continue;
		ll zouguode = 0, dangqianweizhi = a[i];
		ll v = 1, count = 1;
		while (zouguode < m) {
			zouguode += v;
			if (zouguode > m) break;
			dangqianweizhi++;
			if (dangqianweizhi >= n) break;
			ll t = panduan (dangqianweizhi, n);
			if (t > -1) {
				ll ck = a[t];
				ll q = t;
				for (ll i = t; ; i--) {
					if (a[i - 1] != ck) break;
					else q--;
				}
				ll cnt = 0;
				for (ll i = q; i <= n; i++) {
					// printf ("a[i]:%d cankao:%d\n", a[i], cankao);
					if (a[i] == dangqianweizhi) cnt++;
					else break;
				}
				v++;
				count += cnt;
				// printf ("count:%d cnt:%d\n", count, cnt);
			}
			if (zouguode > m) break;
			
		}
		if (count > zd) zd = count;
		// printf ("count:%d zd:%d i:%d zouguode:%d dangqianweizhi:%d\n", count, zd, i, zouguode, dangqianweizhi);
	}
	cout << zd << "\n";
	return 0;
}
