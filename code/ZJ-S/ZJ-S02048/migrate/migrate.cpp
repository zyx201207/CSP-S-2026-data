#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, d;
int a[2000001];
int lst[2000001], aft[2000001];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1, c = 1;i <= n;i++) {
			cin >> a[i];
		}
		for (int i = 1, c= 1;i <= n;i++) {
			while (a[c] - a[i] <= d) c++;
			aft[i] = --c;
		}
		for (int i = n, c= 1;i >= 1;i--) {
			while (a[i] - a[c] <= d) c--;
			lst[i] = ++c;
		}
		int cnt = 0;
		for (int i = 1;i <= n-3;i++) {
			for (int j = i;j <= n;j++) {
				if (abs(lst[j] - aft[i]) == 1) {
					cnt++;
				}
			}
			
		}
		cout << cnt << "\n";
	}
	return 0;
}
