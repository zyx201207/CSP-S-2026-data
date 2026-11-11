#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int ans[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], ans[a[i]] = i;
	if(m == 1) cout << n;
	else if(m == 2) {
		int l1 = -1, l2 = -1, r1 = -1, r2 = -1;
		int ans1 = 0, ans2 = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == 1) {
				ans1++;
				if(l1 == -1) l1 = i;
				else r1 = i;
				if(r1 != -1) {
					if(l2 > l1 && l2 < r1) l2 = -1;
					if(r2 > l1 && r2 < r1) r2 = -1;
					l1 = r1;
					r1 = -1;
				}
				if(l2 != -1) ans2++;
			}
			else if(a[i] == 2) {
				ans2++;
				if(l2 == -1) l2 = i;
				else r2 = i;
				if(r2 != -1) {
					if(l1 > l2 && l1 < r2) l1 = -1;
					if(r1 > l2 && r1 < r2) r1 = -1;
					l2 = r2;
					r2 = -1;
				}
				if(l1 != -1) ans1++;
			}
		}
		cout << ans1 << ' ' << ans2;
	}
	else if(m == n) for(int i = 1; i <= m; i++) cout << i << ' ';
	else if(n >= 5000) for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
