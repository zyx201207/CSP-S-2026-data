#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500009;
ll a[N], s[N], n, m;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	ll ans = 0;
	for (ll i = 1, j = 1; i <= n; i++) {
		while (j < i)
			if ((i - j) * a[i] - (s[i - 1] - s[j - 1]) > m) j++;
			else break;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
/*
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
*/
