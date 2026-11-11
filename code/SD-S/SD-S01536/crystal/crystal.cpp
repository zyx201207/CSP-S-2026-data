#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const int N = 5e5 + 5;
ll n, m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll ans = 1;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++) {
		if ((a[i + 1] - a[i]) * i <= m) {
			ans++;
			m -= (a[i + 1] - a[i]) * i;
		} else {
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
