#include <iostream>
#include <cmath>
#define LCF using
#define AK namespace
#define CSP_J std
LCF AK CSP_J;
int n, m;
const int N = 200005;
int a[N], tmp[N], cnt;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w",stdout);
	cin >> n >> m;
	int maxx = 0;
	for (int i = 1; i <= n; i ++) { 
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	int len = log2(maxx);
	for (int wei = len; wei >= 0; wei --) {
//		cout << wei + 1 << ':';
		int num = 0;
		for (int i = 1; i <= n; i ++) {
//			cout << a[i] << ' ';
			if (a[i] & (1 << wei)) num ++;
		}
//		cout << '\n';
		if (num < m) continue;
		if (num == m) {
			int ans = 2147483647;
			for (int i = 1; i <= n; i ++) {
				if (a[i] & (1 << wei)) {
					ans &= a[i];
				}
			}
			cout << ans;
			return 0;
		}
		for (int i = 1; i <= n; i ++) {
			if (a[i] & (1 << wei)) {
				tmp[++ cnt] = a[i];
			}
		}
//		if (cnt != num) cout << "都怪你lxh";
		n = num;
		for (int i = 1; i <= n; i ++) {
			a[i] = tmp[i];
		}
		cnt = 0;
	}
	for (int i = 2; i <= n; i ++) {
		a[1] &= a[i];
	}
	cout << a[1];
	return 0;
}
/*
9:16开题
咋做
尽量满足最高位
首先大概率nlogn
for(wei[max,0])
	如果集合中这一位有m个以上1：
		那些不是1的从集合中干掉，下一次循环
	否则？
		那就什么都不do，直接下一次循环
	终止条件：某一次正好选出m个数，直接与起来输出
如果一直到结束都>m个数输出0，任何一位都选不出来 

样例：
0011
1111
1100
1100 
4 2
3 15 12 12
*/
