//18:21
#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Sci {
	const int N = 1e6;
	int n, d;
	int a[N], b[N];
	void qud(int _id) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
			int cnt = 0;
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++) {
					int mn = 0, lst = i;
					int sum1 = 0, cnt1 = 0;
					for(int k = i+1; k <= j; k++) {
						if(a[k] - a[lst] > d) {
							lst = k;
							sum1 += a[k-1];
							cnt1++;
						}
					}
					lst = j;
					int sum2 = 0, cnt2 = 0;
					for(int k = j-1; k >= i; k--) {
						if(a[lst] - a[k] > d) {
							lst = k;
							sum2 += a[k+1];
							cnt2++;
						}
					}
					lst = i;
					int sum3 = 0, cnt3 = 0, t = 1;
					for(int k = i+1; k <= j; k++) {
						if(a[k] - a[lst] > d) {
							lst = k - t;
							sum3 += a[k-1-t];
							cnt3++;
							t=0;
						}
					}
					if(sum1 != sum2&&cnt1==cnt2 && (sum1 == sum3 || sum2 == sum3 || cnt3 != cnt1))
						cnt++;
					//cout << i << " " << j << " " << sum1 << " " << sum2 << '\n';
				}
			}
			cout << cnt << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--)
	Sci::qud(c);
	return 0;
}
