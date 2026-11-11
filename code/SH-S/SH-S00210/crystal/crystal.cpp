//双指针O(n) 维护一个滑动窗口 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+5;

int n, ans = 1, dp[MAXN];  //dpi记录i之前能操作几个到i 
ll m, a[MAXN], c[MAXN];  

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) { //处理差分数组 
		c[i] = a[i] - a[i - 1];
	}
	int e = m;
	dp[1] = 1;
	for (int i = 2, j = 1; i <= n; i++) {  //j记录当前左端 
		while (e < c[i] * (i - j)) {
			e += a[i - 1] - a[j];
			j++;
		}
		e -= c[i] * (i - j);
		dp[i] = i - j + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
