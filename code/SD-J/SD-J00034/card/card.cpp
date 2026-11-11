#include <iostream>
#include <cstring>
#include <map>
#define LCF using
#define AK namespace
#define CSP_J std
LCF AK CSP_J;
int n, m;
const int N = 500005, M = 300005;
int a[N], pos[M], now[N], ans[M], cnt;
//↓solveA,m=2用
int cntt[M];
void solvemis2_8pts() {
	for (int i = 1; i <= n; i ++) {
		cntt[a[n]] ++;
		if (a[i] != a[n]) cntt[a[i]] ++;
	}
	cout << cntt[1] << ' ' << cntt[2];
	return;
}
void solveA4pts() {
	for (int i = 1; i <= n; i ++) {
		cntt[a[i]] ++; 
	}
	for (int i = 1; i <= m; i ++){
		cntt[i] += cntt[i - 1];
		cout << cntt[i] << ' ';
	}
	return;
}
int last[M];
void solve_baoli_48pts() {
	for (int i = 1; i <= n; i ++) {
		last[a[i]] = i;
	}
	for (int round = 1; round <= n; round ++) {
		int l = round;
		while (l <= n) {
			ans[a[l]] ++;
			if (last[a[l]] != l) {
				l = last[a[l]];
			}
			l ++;
		}
	}
	for (int i = 1; i <= m; i ++) {
		cout << ans[i] << ' ';
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool isA = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) isA = false;
	}
	if (m == 2) solvemis2_8pts(); 
	else if (isA) solveA4pts();
	else solve_baoli_48pts();
}
/*
9:40开题+鬼屋铃声
小猫钓鱼题？ 
什么情况下这张牌会被留下呢
~~显然~~，最后一张这个牌后面与前面没有相同的牌
吗？ 
并不是
欸还有空调真好 
最后一张这个牌与后面相同的前面所有牌都已经被del掉了 
那就要求与后面相同的最后一张前面牌到指定牌之间，
一定要有一张牌能和前面的其他自己把中间所有不能有的牌都干掉 
所有牌还是所有不能有的牌？
至少是从第一张不能有的到最后一张不能有的
好像有点会了但接着想，10：30想不出来就写暴力 
10：00 鬼屋铃声
如何快速判断对于给定的数字那些局可以？
首先要存下来每个数字出现在那些位置，然后这一堆vec按最后一个数字排序 
啊我们想到了排序
然后对于每个数字就可以O(1)确定那些不可以出现
应该对
吃口零食冷静一下
算先写暴力 
发现：任意时刻最多有M个数 
348pts了够了
OHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH 
改出来了O(nm) 如果CCF机子牛逼就是80辣鸡也是372
 
*/
