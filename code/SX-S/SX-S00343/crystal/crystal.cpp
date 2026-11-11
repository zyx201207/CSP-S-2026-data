#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> pre(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i];
	}
	int l = 0;
	int ans = 0;
	for (int r = 0; r < n; r++) {
		ll need = a[r] * (r - l + 1) - (pre[r + 1] - pre[l]);
		while (need > m) {
			l++;
			need = a[r] * (r - l + 1) - (pre[r + 1] - pre[l]);
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}