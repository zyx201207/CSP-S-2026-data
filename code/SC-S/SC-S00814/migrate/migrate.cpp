#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define max(a, b) a > b ? a : b
using namespace std;

const ll max_l = (ll)1e18; 

ll c, t, n, d, x[2000006];
ll di[505][505];




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ll ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		if (c <= 10){
			for (int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
				di[i][j]=di[j][i]=inf; di[i][i] = 0;
			}
//			
//			x[0] = -inf;
//			
//			for (int i = 1; i <= n; ++i) {
//				int l = 1, r = i;
//				while (l < r) {
//					int mid = (l + r) >> 1;
//					if (x[i] - x[mid] <= d) r = mid;
//					else l = mid + 1;
//				}
//				far[i][0] = l;
//				++rfar[l+1][0];
//				l = i, r = n;
//				int mid = (l + r) >> 1;
//				while (l <= r) {
//					mid = (l + r) >> 1;
//					if (x[mid] - x[i] <= d) l = mid + 1;
//					else r = mid - 1;
//				}
//				far[i][1] = r;
//				++rfar[r-1][1];
//			}
	
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					if (x[j] - x[i] <= d) di[i][j] = di[j][i] = 1;
				}
			}
			
			for (int k = 1; k <= n; ++k) {
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j)
						di[i][j] = min(di[i][j], di[i][k] + di[k][j]);
				}
			}
			
			ll ans = 0;
			
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					bool flag = 1; int cnt = 0;
					for (int k = 1; k <= n; ++k) {
						if (di[i][j] == di[i][k]+di[k][j] && i != k && j != k) {
							++cnt;
							if (cnt > 2) {
								flag = 0; break;
							}
						}
					} if (flag && cnt == 2) ++ans;
				}
			} cout << ans << '\n';

//			for (int i = 1; i <= n; ++i) {
//				int j = far[i][1];
//				ans += rfar[j][0];
//				while (j < n) {
//					j = far[j][1];
//					ans += rfar[j][0];
//				}
//			} cout << ans << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}