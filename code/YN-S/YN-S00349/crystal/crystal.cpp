#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
ll n, m, lz = INT_MIN, flag1 = 0, flag2 = 0;
ll a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			flag1 = 1;
	}
	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			if (a[i] - a[i - 1] != a[2] - a[1])
				flag2 = 1;
		}
	}
	sort(a + 1, a + n + 1);
	ll js = 0;
	for (int i = 2; i <= n; i++) {
		js += (a[i] - a[i - 1]) * (i - 1);
	}
	if (js <= m) {
		cout << n << "\n";
	} else if (flag1 == 0) {
		ll cnt = 0, flag = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt + i > m) {
				flag = 1;
				cout << i << "\n";
				break;
			}
			cnt += i;
		}
		if (flag == 0)
			cout << n << "\n";
	} else if (flag2 == 0) {
		ll cs = m / (a[2] - a[1]), cnt = 0, flag = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt + i > cs) {
				flag = 1;
				cout << i << "\n";
				break;
			}
			cnt += i;
		}
		if (flag == 0)
			cout << n << "\n";
	} else {
		for (int i = 1; i <= n; i++) {
			ll cnt = 0;
			for (int j = i + 1; j <= n; j++) {
				if (cnt + (a[j] - a[j - 1]) * (j - i + 1) > m) {
					ll cd = j - i + 1;
					lz = max(lz, cd);
					break;
				} else {
					ll cd = j - i + 1;
					lz = max(lz, cd);
				}
				cnt += (a[j] - a[j - 1]) * (j - i + 1);
			}
			if (lz == n)
				break;
		}
		cout << lz << "\n";
	}
	return 0;
}