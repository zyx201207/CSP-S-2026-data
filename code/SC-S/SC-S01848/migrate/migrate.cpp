#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXX = 2e6 + 5;
int a[MAXX];
signed main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	freopen ("migrate.in" , "r" , stdin);
	freopen ("migrate.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	while (t--) {
		int n , d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++){
				if ((a[j] - a[i] > d && (a[j] - a[i]) < 2 * d) && (a[j] - a[i]) % d != 0 && j - i > 2) {
//					cout << j << i << endl;
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
} 