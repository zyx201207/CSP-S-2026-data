#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], d[N], wrt;

void so() {
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
//	d[1] = a[1];
//	for (int i = 2 ; i <= n ; i++) d[i] = d[i - 1] & a[i];
//	for (int i = 1 ; i <= n ; i++) cout << d[i] << " ";
//	cout << "\n";
	sort(a + 1, a + n + 1);
	for (int i = 1 ; i <= n ; i++) {
//		if (i + m - 1 > n) break;
//		int x = -1;
//		x ^= d[i + m - 1] ^ (~d[i - 1]);
//		wrt = max(wrt, x);
//		cout << x << "\n";
		int x = a[i];
		for (int j = i + 1 ; j <= i + m - 1 ; j++) x &= a[j];
//		cout << x << " ";
		wrt = max(wrt, x);
	}
	cout << wrt << "\n";
} 

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) so();
	return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
!@#$%^&*()_+[]{}~`¡¤
1234567890
5 3
31 3 1 15 7

4 2
3 15 12 12

*/



