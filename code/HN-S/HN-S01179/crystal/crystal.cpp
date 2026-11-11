#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int W = 5e5 + 5;
ll n, m, ans;
ll a[W], p[W];
int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + ((a[i] - a[i - 1]) * (i - 1));
		if (p[i] - p[i - 1] > m) {
			n = i - 1;
			break;
		}
	}
	//for (int i = 1; i <= n; i++) cout << p[i] << ' ';
	//cout << '\n';
	for (ll i = 1, j = 1; i <= n && j <= n;) {
		ll num = p[j] - ((i - 1) * (a[j] - a[i - 1]) + p[i - 1]);
		if (num <= m) {
			ans = max(ans, j - i + 1);
			j++;
		} else {
			i++;
		}
	}
	cout << ans;
	return 0;
} 
