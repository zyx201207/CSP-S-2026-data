#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 2e6 + 9;
int c, t; 
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--) {
		int n, d, ans = 0;
		cin >> n >> d;
		d = 2 * d - 1;
		vector<int> a(N, 0), pos(N, 0);
		for(int i = 1; i <= n; ++i) cin >> a[i];
		if(a[1] >= 0) {
			for(int i = 1; i <= n; ++i) 
				pos[a[i]]++;
		}
		else {
			int cnt = 0 - a[1];
			for(int i = 1; i <= n; ++i) a[i] += cnt, pos[a[i]]++;
		}
		for(int i = 1; a[i] + d <= a[n] && i <= n; ++i) {
			if(pos[i] == 0) continue;
			bool flag = true;
			for(int j = a[i]; j <= a[i + d]; ++j) {
				if(pos[j] == 0) {
					flag = false;
					break;
				}
			}
			if(flag) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
