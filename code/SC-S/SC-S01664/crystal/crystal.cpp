#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
const int N = 500010;
int a[N];

int read();

//int ans;

int sum[N];
int pre[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	
	for (int i = 1; i <= n; i ++)
		a[i] = read();
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i];
	
//	// 暴力：选择每个为目标能量，1 不用考虑，复杂度：O(n)
//	for (int i = 2; i <= n; i ++) {
//		int cnt = 0, sum = 1;
//		for (int j = i - 1; j >= 1; j --) {
//			int x = a[i] - a[j];
//			if (cnt + x <= m) {
//				cnt += x;
//				sum ++;
//			}
//			else
//				break;
//		}
//		ans = max(ans, sum);
//	}
	
	// 发现：每次要么消耗+(i-1)*(a[i]-a[i-1])，ans++，要么不考虑。还可以从 i-x 变过去。。。好烦啊
	
	int ans = 1;
	
	for (int i = 2; i <= n; i ++) {
		sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		if (sum[i] <= m)
			ans ++;
		int x = sum[i];
//		for (int j = 1; j <= i - ans; j ++) {
//			int k = x - j * a[i] + pre[j];
////			cout << a[i] << ' ' << pre[j] << endl;
//			if (k <= m) {
//				ans = max(ans, i - j);
//				break;
//			}
//		}
		// 优化，现在要找到那个 j 的最大值使 k <= m
		int l = 1, r = n;
		while (l <= r) {
			int mid = l + r >> 1;
			int o = x + pre[mid] - mid * a[i];
			if (o > m)
				l = mid + 1;
			else
				r = mid - 1;
		}
		int k = x - l * a[i] + pre[l];
		ans = max(ans, i - l);
	}
	
	cout << ans;
	
	return 0;
}

/*
理解错题意了。。。。
*/

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	
	return x * f;
}