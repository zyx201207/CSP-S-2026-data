#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005], n, m, mmax = -1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ll tem = -20;
	for (int j = 1; j <= 50; j++) {
//		ll tem = a[j];
		ll ans = 0;
		ll sum = m;
		for (int i = 1; i <= n; i++) {
			if (a[i] == tem) {
				ans++;
				continue;
			}
			if (a[i] < tem) {
				ll q = tem - a[i];
				if (sum >= q) {
					sum -= q;
					ans++;
				} else
					break;
			}
			if (a[i] > tem)
				break;
		}
		mmax = max(mmax, ans);
		tem++;
	}
	cout << mmax;
	return 0;
}
