#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 10;

ll n, m, a[N], ans[N] = {0}, t = 1;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (t <= n) {
		t++;
		ll s[N] = {0}, k = 1;
		ll f[N] = {-1};
		for (int i = t; i <= n; i++) {
			if (f[a[i]] == -1) {
				f[a[i]] = k;
				s[k] = a[i];
				k++;
			} else {
				k = f[a[i]] + 1;
				for (int j = k; j < i; j++)
					f[s[j]] = -1;

			}
		}
		for (int i = t; i < k; k++) {
			ans[s[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}