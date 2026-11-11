#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
int ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	int d = a[2] - a[1]; bool flag = false;
	for(int i = 3; i <= n; i ++) if(d != a[i] - a[i - 1]) flag = true;
	if(!flag) {
		for(int x = n; x >= 1; x --)
			if(d * x * (x - 1) <= 2 * m) {
				cout << x << endl;
				return 0;
			}
	}
	
	for(int i = 1; i <= n; i ++) {
		int j, cnt = 0;
		for(j = i; j >= 1; j --)
			if(cnt + a[i] - a[j] <= m) cnt += a[i] - a[j];
			else break;
		j ++;
		ans = max(ans, i - j + 1);
	}
	cout << ans << endl;
	
	return 0;
}
