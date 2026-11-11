#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 300 + 10;
int c, t, n, d;
int x[N], cnt, ans;
bool st[N][N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	
	if(c == 11 || c == 12) {
		while(t --) {
			cin >> n >> d;
			for(int i = 1; i <= n; i ++) cin >> x[i];
			int ans = 0;
			int l = x[2] - x[1];
			for(int k = 1; k <= d / l; k ++)
				if((k + 1) * l <= d && d < (2 * k + 1) * l)
					ans += max(0ll, n - (2 * k + 1));
			cout << ans << endl;
		}
		return 0;
	}
	
	while(t --) {
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> x[i];
		for(int i = 1; i <= n; i ++)
			for(int j = i; j <= n; j ++)
				if(x[j] - x[i] <= d) st[i][j] = 1, st[j][i] = 1;
				else st[i][j] = 0, st[j][i] = 0;
		ans = 0;
		for(int i = 1; i <= n; i ++)
			for(int j = i; j <= n; j ++)
				if(!st[i][j]) {
					int cnt = 0;
					for(int k = 1; k <= n; k ++)
						if(st[i][k] && st[j][k])
							cnt ++;
					if(cnt == 2) ans ++;
				}
		cout << ans << endl;
	}
	
	return 0;
}
