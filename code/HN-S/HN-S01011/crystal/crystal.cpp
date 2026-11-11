#include<bits/stdc++.h>
using namespace std;
int n, m, a[500001];
long long s[500001]; 
bool check(int len) {
	for (int i = 1; i <= n - len + 1; i++) {
		if (1ll * a[i + len - 1] * len - s[i + len - 1] + s[i - 1] <= m) {
			return 1;
		}
	}
	return 0;
} 
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	} 
	int l = 1, r = n;
	while (r - l > 1) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l;
} 
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		solve();
	} 
}
/*

引理1：最后参与合成水晶的能量值一定在 a 中出现过。

引理2：最后参与合成水晶的水晶的原先能量在排序后一定在 a 数组中连续，且大水晶的能量值一定是最后一个。 

*/ 
