#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const int maxn = 5e5 + 5;
ll a[maxn];
ll ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	for (int i = n; i >= ans; i--) {

		ll ptr1 = i - 1, cnt = 1;
		ll m2 = m;

		while (ptr1 > 0 && m2 > 0) {
			if (m2 - (a[i] - a[ptr1]) >= 0) {
				m2 -= (a[i] - a[ptr1]);
				cnt++;
				ptr1--;
			} else {
				break;
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans;
	return 0;
}