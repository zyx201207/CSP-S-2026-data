#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
ll a[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if (m == 1) {
		cout << a[n - 1];
		return 0;
	}
	int ans = a[n - 1] & a[n - 2];
	for (int i = n - 2; i > n - 1 - m; i--)
		ans = ans & a[i];
	cout << ans;
	return 0;
}