#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
typedef long long ll;
ll n, m, a[N];
ll ans;
void solve () {
	ll sum = 0;
	sort(a + 1 , a + 1 + n);
	int i;
	for (i = 2; i <= n; i++) {
		ll c = a[i] - a[i - 1];
		sum += 1LL * c * (i - 1);
		if (sum > m) 
			break;
	}
	cout << i - 1;
}

int main () {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			ll sum = 0, cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (a[j] <= a[i]) {
					sum += a[i] - a[j];
					cnt++;
				}
			}
			if (sum <= m) 
				ans = max(ans , cnt);
		}
		cout << ans;
	} else {
		solve();
	}
	return 0;
}
