#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int n, m, a[N];
int maxx = -1e18;
int cha[N];
bool tsA = true, tsB = true;
signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		if (a[i] != i) {
			tsA = false;
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i < n; i++) {
		if (a[i + 1] - a[i] != a[i] - a[i - 1]) {
			tsB = false;
		}
	}
	// 将一些水晶增加一些能量值，但是总和不超过 m
	// 问最多有多少个相等的元素
	// 可以先得特殊性质+暴力 90 pts，机子不好的话 80 pts 
	if (tsB == true || tsA == true) {
		// 公差为
		int d = a[n] - a[n - 1];
		int ans = m / (d + 1) + 1;
		cout << ans; 
	}
	else {
		int ans = 0;
		for (int i = 1; i <= maxx; i++) {
			for (int j = 1; j <= n; j++) {
				cha[j] = i - a[j];
			}
			// 左边最大，右边最小
			int sum = 0, now = 0;
			for (int j = 1; j <= n; j++) {
				if (cha[j] < 0) {
					break;
				}
				sum += cha[j];
				if (sum > m) {
					break;
				}
				if (sum <= m) {
					now = j;
				}
			}
			ans = max(ans, now);
		}
		cout << ans;
	}
	return 0;
}
