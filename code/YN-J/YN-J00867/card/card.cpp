#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll n, m, a[N], b[N], ans[N];

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	// be sure to delete any "//" on this line!!!!!!!!
	// be sure to change the file name
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll l = -1, idx = -1;
	for (ll i = n; i >= 1; i--) {
		if (b[a[i]] == 0)
			b[a[i]] = i;
		ll tmpl = l;
		ll tmpidx = idx;
		if (b[a[i]] && b[a[i]] != i) {
			l = a[i];
			idx = i;
		}

		ll tmpbl = b[l];
		/*
				if (l != -1 && tmpidx != -1) {
					//cout << l << "\n";
					for (int j = i; j < tmpidx; j++) {
						ans[j] += j - i;
						b[a[j]] = 0;
						cout << j - i << " ";
					}
				}
		*/
		for (int j = max(i, b[tmpl]) + 1; j < tmpbl; j++) {
			ans[j] += b[j] - i;
			b[a[j]] = 0;
			//cout << j << " " << b[j] - i << " ";
		}
		if (l != -1)
			b[l] = tmpbl;
		//cout << l << " ";
	}
	for (int i = 1; i <= m; i++) {
		ans[i] += b[i];
		//cout << b[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}