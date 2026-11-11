#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int i = 1;
	int cnti = 1, cntj = n;
	int ans = 0;
	int mid = sum / 2;
	while (i <= mid) {
		char x = c[cnti], y = c[cntj];
		int l = min(a[cnti], a[cntj]);
		if (x == y) {
			if (i += l > mid) {
				break;
			}
		} else {
			ans += l;
		}
		i += l;
		a[cnti] -= l;
		a[cntj] -= l;
		if (a[cnti] == 0) cnti++;
		if (a[cntj] == 0) cntj--;
	}
	cout << ans;
	return 0;
}
/*

*/
