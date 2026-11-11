#include <bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
int n, m, a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int r = 1, ans = 1, sum = 0;
	for(int l = 1; l <= n; l++) {
		while(r <= n && sum <= m) {
			sum += (r - l + 1) * (a[r + 1] - a[r]);
			r++;
		}
		ans = max(ans, r - l);
		sum -= a[r] - a[l];
	}
	cout << ans;
	return 0;
}
/*
// freopen("crystal2.in", "r", stdin);
// freopen("crystal.out", "w", stdout);
QQ 2460124386
lg 804115
星穹铁道uid多少来着，忘了 
t1太简单了不需要记录做法 
这就是我的游记
现在是14:55，我t2已经会了一个O(md^2+n^3+qd^2)的做法
3e8多1s稍微有点卡，不过现在比赛才开始25分钟，我有足够的时间
心态+=INF
其实相信CCF机子也可以（ 
现在是14:57，我们先再往后想些分数再开始写

怎么没有employ，严厉谴责某某某，考前复习的dp成为了滚木

直觉告诉我t3更像一个dp题
我们考虑怎么判定，这是一个内部的dp过程，外面要计数，不会是什么dp of dp吧
具体思考过程我还是放到migrate.cpp
ddl 15:30，到这个点t3想了多少分都先去写t1t2
15:22 我要开写了
这键盘好难用，这空格需要超级大的力度才能按下去
15:31 T1过大样例
ber为啥我黑窗口在上头我按enter打开了文件，啥阴
好像看见zyh了

15:54 okt2过大样例，subway7几乎开满了才0.5s，那我放心了
进展意外地好啊，1.5h两个题了
一等到手后面就可以放开打了，没有后顾之忧了
我的巧克力怎么化了/ll

16:02 设一个一小时的ddl免得暴力分都没了

16:56 我会t3了真的假的？！有无说法 
17:29 哦不我的空间被卡了，给我开2G好不好

18:07 冲了2h的t3假了，我好开心，哈哈哈哈哈哈哈
又是满盘皆输的一年 
*/
