#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N];
ll n, m;
bool flagg = true;
bool flaggg = true;
ll ans = 1;


void solve1() {
	for (int i = 1; i <= n; i++) {
		ll ans1 = 1;
		ll mm = m;
		for (int j = i - 1; j >= 1; j--) {
			if (mm >= a[i] - a[i]) {
				ans1++;
				mm -= a[i] - a[j];
			} else
				break;
		}
		ans = max(ans1, ans);
	}
	cout << ans;
}



int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w"., stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			flagg = false;
		}
		if (i >= 3) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				flaggg = false;
			}
		}
	}
	sort(a + 1, a + 1 + n);
	if (n <= 5000) {
		solve1();
		return 0;

	} else {
		if (flagg) {
			ll mem = 1;
			for (ll i = 1; i < n; i++) {
				ll sum = (1 + i) * i / 2 * 1ll;

				if (sum > m) {
					cout << i << endl;
					break;
				} else
					mem = sum;
			}
		}
		if (flaggg) {
			ll sum = 1;
			ll d = a[n] - a[n - 1];
			ll dd = d;
			for (ll i = 1; i < n; i++) {
				if (m >= dd) {
					m -= dd;
					sum++;
				} else {
					cout << sum;
					break;
				}
				dd += d;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
