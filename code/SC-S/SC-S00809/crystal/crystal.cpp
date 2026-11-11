#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n, m, a[N], ans, sum;
int main() {
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	long long l = 1, r = 1;
	while (r <= n) {
		ans = max(ans, r - l + 1);
		long long val = (r - l + 1) * (a[r + 1] - a[r]);
		while (l <= r) {
			if (sum <= m - val) break;
			sum -= a[r + 1] - a[l], l++;
		}
		sum += val, r++;
//		cout << l << " " << r << "\n";
	}
	cout << max(ans, r - l);
	return 0;  
}
/*
5 8
-3 -1 2 2 7

5 5 
1 2 4 8 9

13 0
-3 -3 -3 2 2 2 2 2 2 2 2 2 2

*/
/*
#### 游记

我去了，这键盘怎么这么难用

居然因为密码延迟，所以所有人可以多考 5min，太棒了！！！

md 第一题不会，又是双指针

16:00:17 T1 100pts（ps：从暴力到正解真是个好东西）

16:01:42 吃了个巧克力球

17:11:01 T2 32 ~ 84pts（ps：dijkstra 的时间复杂度是多少捏？）

18:17:17 T3 的数据范围很人才了
*/