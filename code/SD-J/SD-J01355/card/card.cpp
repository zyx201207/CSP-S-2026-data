#include <bits/stdc++.h>
#define ilv inline void
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

typedef long long ll;

const int N = 500005; 

int n, m, a[N], lst[N], f[N];

inline void rd(int &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
void wrt(int x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48); 
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	rd(n), rd(m);
	rep(i, 1, n) rd(a[i]), lst[a[i]] = i;
	rep(i, 1, n) f[lst[a[i]]]++;
	repr(i, 1, n) if (i == lst[a[i]]) f[lst[a[i + 1]]] += f[i];
	rep(i, 1, m) wrt(f[lst[i]]), putchar(" \n"[i == m]);
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

/*
嘲笑谁恃美扬威
没了心如何相配
盘铃声清脆 帷幕间灯火幽微
我和你 最天生一对

没了心如何相片
没了你才算原罪
你褴褛 我彩绘
并肩行过山与水
你憔悴 我挺你明媚

是你吻开笔墨 染我眼角浊泪
演离合相遇悲喜为谁
他们迂回误会 我却只由你支配
问世间 哪有更完美

兰花指捻 红尘似水
三尺红台 完事入歌吹
唱别久悲不成悲
十分红处竟成灰
愿谁记得谁 最好的年岁

你一牵我舞如飞
你一引我懂进退
苦乐都跟随 举手投足不违背
将谦卑 温柔成绝对

你错我不肯对 你懵懂我明媚
心火怎甘心洋洋止沸
你枯我不曾萎 你倦我也不敢累
用什么 暖你一千岁 
 
风雪依稀 秋白发尾
灯火葳蕤 柔皱你眼眉
假如你舍一滴泪 假如老去我能陪
烟波里成灰 也去的完美 
*/
