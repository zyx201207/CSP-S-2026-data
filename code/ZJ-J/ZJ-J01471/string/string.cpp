#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int n, a[N], b[N];
char c[N], d[N];
int ans, cnt1 = 1, cnt2 = 1;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i] >> c[i];
	for(int i = 1; i <= n; i ++) b[i] = a[n - i + 1], d[i] = c[n - i + 1];
	for(int i = 1; cnt1 <= n && cnt2 <= n; i ++) {
		int l = min(a[cnt1], b[cnt2]);
		if(c[cnt1] != d[cnt2]) ans += l;
		a[cnt1] -= l, b[cnt2] -= l;
		if(a[cnt1] == 0) cnt1 ++;
		if(b[cnt2] == 0) cnt2 ++;
	}
	cout << ans / 2 << endl;
	
	return 0;
}
