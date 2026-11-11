#include <bits/stdc++.h>
#define LL long long
#define int long long
using namespace std;
const int N = 2e6+5;
int n, d, c, t;
int a[N];
//bitset<N> vis[N];
//int cnt[N][N], dis[N][N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
	
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		} 
//		for (int i = 2; i <= n; i++) {
//			if (a[i] - a[i-1] != a[2] - a[1]) {
//				dif = 0;
//				break;
//			}
//		} 
		if (c == 13 || c == 14 || c == 0) {
			int dd = 0;
			for (int i = 2; i <= n; i++) {
				if (a[i] - a[1] > d) {
					dd = i-2;
					break;
				}
			}
			LL tt = n / dd-1, xx = n % dd+1;
//			cout << tt << ' ' << xx << endl;
			if (dd == 0) cout << 0 << '\n';
			else cout <<   (tt+1)*tt / 2 *xx<< '\n';
		}
			
	}
	
	return 0;
} 