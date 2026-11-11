#include<bits/stdc++.h>
using namespace std;
long long s[2000010], ans;
long long n, d;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++) cin >> s[i];
		if (d >= s[n] - s[1]) {
			cout << 0 << '\n';
			continue;
		}
		long long xd = s[2] - s[1];              
		if (xd < 0) xd = -xd;    
		int r = d / xd;
		if (d == 1 || d < xd) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++) {
			int j = i + 2 * r - 1;
			if (j <= n)ans++;
		}
		cout << ans <<'\n';
	}                                 
	return 0;
}                     
      