#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	freopen ("hub.in" , "r" , stdin);
	freopen ("hub.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n , k;
		cin >> n >> k;
		int maxm = 1e9 , minn = -1e9;
		for (int i = 1; i <= n - 1; i++) {
			int u , v;
			cin >> u >> v;
			maxm = max (maxm , u);
			minn = min (minn , v);
		}
		cout << maxm - minn << endl;
	}
}