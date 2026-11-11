#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;

const int N = 5e5 + 3;

ll n, m, a[N];
ll ans = 1;

signed main() {
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll sum = 0;
	for (ll i = 2, l = 1; i <= n; i++) {
		sum += (i - l) * (a[i] - a[i - 1]);
		for (; sum > m && l < i; sum -= (a[i] - a[l]), l++);
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
