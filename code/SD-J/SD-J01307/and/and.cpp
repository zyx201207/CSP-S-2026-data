#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], h;
int b[31];
int lowbit(int x) {
	return x & -x;
}
bool cmp(int x, int y) {
	for (int i = h; i >= 0; i--) {
		if (((x >> i) & 1) == ((y >> i) & 1)) continue;
		else return ((x >> i) & 1); 
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 31; j >= 0; j--) {
			if ((a[i] >> j) & 1) b[j]++;
		}
	}
	for (int i = 31; i >= 0; i--) {
		if (b[i] >= m) {
			h = i;
			break;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = a[1], cnt = 0;
	for (int i = 2; i <= m; i++) {
		if (!((i >> h) & 1)) {
			for (int j = h; j >= 0; j--) {
				if (b[j] >= m) {
					h = j;
					break;
				}
			}
		}
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/

