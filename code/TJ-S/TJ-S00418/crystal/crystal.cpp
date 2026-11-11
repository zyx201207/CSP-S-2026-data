#include <bits/stdc++.h>

using namespace std;

/*
首先不妨把 a 排序
考虑枚举一下相等的那个值是谁，假设是 a[i]
显然，把这个值选成某个 a[i] 是优的，因为是至多 m 次
注意到只能 + 1
我们从 a[i - 1] 开始考虑，看看变成 a[i] 需要多少次操作...
这样其实就是，需要二分或者双指针，看钦定变成 a[i] 至多能变多少个
求前缀和 s
假设左指针是 l，考虑 a[l...i] 能否都变成 a[i]
其实就是看 (i - l + 1) * a[i] - (s[i] - s[l - 1])
这个数应该 <= m 才行，如果 > m 的话 l 要右移 
我们看一下会不会爆数据范围
和最大是 5e17，操作次数应该最大是 1e18 左右
开 long long 足够 
*/

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef unsigned long long ULL;

const int N = 5e5 + 10;

LL n, m, a[N];

namespace subtask_all {
	LL s[N];
	
	void solve() {
		sort(a + 1, a + n + 1);
		s[0] = 0;
		for (int i = 1; i <= n; i++) {
			s[i] = s[i - 1] + a[i];
		}
	
		LL res = 0;
		LL l = 1;
		for (int i = 1; i <= n; i++) {
			while (l <= i) {
				LL cnt = (i - l + 1) * a[i] - (s[i] - s[l - 1]);
				if (cnt <= m) {
					break;
				} else {
					l++;
				}
			}
			
			res = max(res, i - l + 1);
		}
		
		cout << res << "\n";
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	
	subtask_all::solve();
}

int main() {
	#ifndef LOCAL_TEST
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
} 
