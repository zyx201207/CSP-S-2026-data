#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5 + 5;
int n, m, a[N], r = -1, l = 1;
__int64 sum = 0;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout);
//	freopen("crystal4.in", "r", stdin);
	cin >> n >> m;
	if(m == 0) {
		cout << 1;
		return 0;
	} 
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	*a = a[1];
	for(int i = 1;i <= n;i ++) {
		sum += (a[i] - a[i - 1]) * (i - 1);
//		cout << sum << "\n";
		if(sum > m) {
			r = i - 1;
			break;
		}
	}
	if(r == -1) {
		cout << n;
		return 0;
	}
//	cout << (r - l + 1) << "\n";
	while(l <= n && r <= n) {
		int len = r - l + 1;
//		cout << "len:" << len << "  right:" << r << "  left:" << l << "\n";
//		if((a[r] - a[l]) <= (a[r + 1] - a[r]) * (len - 1)) break; 
		int tmp = a[r] - a[l];
		int nl = l + 1, nlen = len - 1, nr = r;
		while((a[nr + 1] - a[nr]) * nlen <= tmp && nr <= n) nr ++, nlen ++;
		if(nlen >= len) r = nr, l = nl;
		else break;
	}
	cout << r - l + 1;
	return 0;
}