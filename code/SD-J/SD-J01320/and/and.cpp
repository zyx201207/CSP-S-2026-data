#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 2e5 + 5, T = 816;
int n, m, a[SIZE], ans;
bool flg[SIZE];
void _main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)flg[i] = 1;
	for (int i = 31; i >= 0; i--) {
		int cur = 1 << i, cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!flg[j]) continue;
			if (a[j] & cur) cnt++;
		}
		if (cnt >= m){
			ans += cur;
			for (int j = 1; j <= n; j++) {
				if (!flg[j]) continue;
				if ((a[j] & cur) == 0) flg[j] = 0;
			}
		}
	}
	cout << ans;
	return;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while (t --> (T^T)){
		_main();
	}
	return 0; 
}
