#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, f;
ll a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			f = 1;
	}
	sort(a + 1, a + n + 1);
	ll c = (a[2] - a[1]), ans = 0, tot = 1;
	while (ans + tot * c <= m) {
		ans += tot * c;
		tot++;
	}
	if (f == 0)
	{
		cout << tot - 1;
		return  0;
	}
	ans = 0;
	for (ll i = 1; i <= n; i++) {
		tot = 0;
		for (ll j = i; j >= 1; j--) {
			tot += a[i] - a[j];
			if (tot <= m)
				ans = max(ans, i - j + 1);
		}
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
