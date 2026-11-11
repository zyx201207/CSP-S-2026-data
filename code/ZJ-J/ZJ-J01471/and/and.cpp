#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10, K = 30;
int n, m, num, ans;
int a[N];
bool st[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	num = n;
	for(int k = K; k >= 0; k --) {
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			if(!st[i] && !((a[i] >> k) & 1))
				cnt ++;
		if(num - cnt < m) continue;
		num -= cnt;
		for(int i = 1; i <= n; i ++)
			if(!st[i] && !((a[i] >> k) & 1))
				st[i] = true;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if(cnt == m) break;
		if(!st[i]) {
			if(ans == 0) ans = a[i];
			else ans = ans & a[i];
			cnt ++;
		}
	}
	cout << ans << endl;
	
	return 0;
}
