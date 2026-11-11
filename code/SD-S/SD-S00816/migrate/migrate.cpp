#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, a[2000005], s;
void solve() {
	int flag = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1 && a[i] - a[i - 1] > d) {
			flag = 1;
		}
	}
	if (flag) {
		cout << 0 << '\n';
		return ;
	}
	int ans = 0;
	s = a[2] - a[1];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			int x = a[j] - a[i];
			if (x > d) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
