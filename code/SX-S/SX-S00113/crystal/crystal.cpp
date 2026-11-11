#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll n, m, a[N], mx = -1, my = -1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		ll ans = 0, cnt = 0;
		for (int j = 0; j < n - i; j++) {
			ans += a[j];
			cnt += a[n - i - 1];
		}
		if (cnt - ans <= m) {
			mx = max(mx, n - i);
		}
	}
	for (int i = 0; i < n; i++) {
		ll ans = 0, cnt = 0;
		for (int j = i; j < n; j++) {
			ans += a[j];
			cnt += a[n - 1];
		}
		if (cnt - ans <= m) {
			my = max(my, n - i);
		}
	}
	cout << max(mx, my);
	return 0;
}
