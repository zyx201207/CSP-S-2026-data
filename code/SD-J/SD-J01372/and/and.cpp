#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int start = (1 << 30) - 1;
int n, m, a[maxn], ans = start;
namespace onetofive {
	int ans = -inf;
	void dfs(int pos, int now, int number) { // 表示到了pos位置现在的结果是now用了number个数 
		if (number == m) { // 选完了 
			ans = max(ans, now);
			return;
		} if (pos == n+1) { // 到n+1且没有选完，也不能选了 
			return;
		} if (now < ans) {
			return;
		} // 最优性剪枝 
		dfs(pos+1, now bitand a[pos], number+1); // 选
		dfs(pos+1, now, number); // 不选 
	}
}
namespace six {
	int ans = -inf;
	int solve() {
		rep(i, 1, n) {
			ans = max(ans, a[i]);
		}
		return ans;
	}
}
namespace seven {
	int ans = start;
	int solve() {
		rep(i, 1, n) {
			ans = ans bitand a[i];
		}
		return ans;
	}
}
namespace eighttoten {
	int ans = -inf;
	int solve() {
		rep(i, 1, n) {
			rep(j, i+1, n) {
				ans = max(ans, a[j] bitand a[i]);
			}
		}
		return ans;
	}
}
namespace eleventotwelve {
	int st[maxn], suf[maxn], ans = -inf;
	void init() {
		st[0] = start;
		rep(i, 1, n) {
			st[i] = st[i-1] bitand a[i];
		}
		suf[n+1] = start;
		per(i, n, 1) {
			suf[i] = suf[i+1] bitand a[i];
		}
	}
	int solve() {
		init();
		rep(i, 1, n) {
			ans = max(ans, st[i-1] bitand suf[i+1]);
		}
		cout << ans;
	}
}
namespace thirteen {
	int ans = start;
	bool cmp(int x, int y) {
		return x > y;
	}
	int solve() {
		sort(a+1, a+1+n, cmp);
		rep(i, 1, m) {
			ans &= a[i];
		}
		cout << ans;
	}
}
bool pan() {
	bool flg = 1;
	rep(i, 1, n) {
		flg &= (a[i] == i-1);
	}
	return flg;
}
bool ppan() {
	bool flg = 1;
	rep(i, 1, n) {
		flg &= (a[i] == 4);
	}
	return flg;
}
int solve() {
	int num3 = 0, num2 = 0, num1 = 0, num0 = 0;
	rep(i, 1, n) {
		switch (a[i]) {
			case 0: {
				++num0;
				break;
			}
			case 1: {
				++num1;
				break;
			}
			case 2: {
				++num2;
				break;
			}
			case 3: {
				++num3;
				break;
			}
		}
	} if (num3 >= m) {
		return 3;
	} else if (num3 + num2 >= m) {
		return 2;
	} else if (num3 + num1 >= m) {
		return 1;
	} else {
		return 0;
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
	} if (n <= 20) {
		onetofive::dfs(1, start, 0);
		cout << onetofive::ans;
	} else if (m == 1) {
		cout << six::solve();
	} else if (m == n) {
		cout << seven::solve();
	} else if (m == 2) {
		cout << eighttoten::solve();
	} else if (m == n-1) {
		cout << eleventotwelve::solve();
	} else if (pan()) {
		per(i, n, n-m+1) {
			ans = ans bitand a[i];
		}
		cout << ans;
	} else if (ppan()) {
		cout << solve();
	} else {
		cout << thirteen::solve(); 
	}
}
/*
//freopen
frepoen
froepen
SD-S00999祭。
goal：J 300+, S 1= 
退役快乐！
password： Trick||Treat! 
考虑双指针。 
开题顺序：BACD
本题目标：80pts。
1~5(n <= 20)：
此时我们完全可以使用暴力。 
6(m = 1):
输出最大值即可。 
7(m = n):
全部或一遍即可。 
8~10(m = 2)：
O(n^2)暴力即可。 
11~12(m = n - 1):
重头戏开始了。
预处理前缀后缀and和就可以了。 
13(a_i二进制为111...111):
最大的m个。 
14~15(a_i = i-1):
O(n)先判定，然后就做完了。
16~17(a_i < 4):
记录数字。 
*/
