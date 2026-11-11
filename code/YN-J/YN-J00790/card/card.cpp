#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 5e5 + 5;
int a[N];
int bj[N];
int ans[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {

			if (bj[a[j]] != 0) {
				//cout << 100 + bj[a[j]] << endl;
				for (int fi = bj[a[j]]; fi <= j; fi++) {
					bj[fi] = 0;
				}
			}
			bj[a[j]] = j;
		}
		for (int fi = 1; fi <= m ; fi++) {
			if (bj[fi] != 0) {
				ans[fi]++;
				//cout << ans[fi] << " ";
			}
		}
		for (int fi = 1; fi <= m ; fi++) {
			bj[fi] = 0;
		}
		//cout << endl;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
