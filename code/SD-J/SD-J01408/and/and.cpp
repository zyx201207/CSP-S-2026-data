#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N], n, m, c[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = 1;
	}
	int ans = 0;
	for(int i = 31; i >= 0; i--) {
		int cot = 0;
		for(int j = 1; j <= n; j++) if(c[j]) cot += (a[j] >> i) & 1;
		if(cot >= m) {
			ans = (ans << 1) + 1;
			for(int j = 1; j <= n; j++) {
				if(((a[j] >> i) & 1) == 0) c[j] = 0;
			}
		} else {
			ans <<= 1;
		}
//		cout << ans << endl;
	}
	cout << ans;
	return 0; 
}
