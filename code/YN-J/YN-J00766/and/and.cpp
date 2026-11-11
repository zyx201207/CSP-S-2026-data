#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[200005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		sort(a + 1, a + n + 1);
		cout << a[n] << '\n';
		return 0;
	}
	if (m == n) {
		int  ans = a[1];
		for (int i = 1; i <= n; i++) {
			ans = ans & a[i];
		}
		cout << ans << '\n';
		return 0;
	}
	if (m == 2) {
		int maxx = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					int ans = a[i] & a[j];
					maxx = max(maxx, ans);
				}
			}
		}
		cout << maxx  << '\n';
	}
	if (n > 2000) {
		long long ans = 0;
		sort(a + 1, a + n + 1);
		cout << a[1];
	}

	return 0;
}
//1.一奇一偶 奇数-偶数=1 奇数&偶数=偶数
//2.两数相同 &得本身
//3.与0相与得0
//4.若最大的是2的幂，则得0
//5.一偶一奇 偶数-奇数=1 奇数&偶数=第一个小于偶数的2的幂
//6.2的幂与2的幂-1相&得较小数
