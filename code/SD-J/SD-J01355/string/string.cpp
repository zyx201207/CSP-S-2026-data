#include <bits/stdc++.h>
#define ilv inline void
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;

typedef long long ll;

const int N = 200005; 

int n, a[N];
char c[N]; 

inline void rd(int &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	rd(n);
	rep(i, 1, n) {
		rd(a[i]);
		while (isspace(c[i] = getchar()));
	}
	ll ans = 0;
	int p1 = 1, r1 = a[1], p2 = n, r2 = a[n];
	while (p1 != p2) {
		if (r1 < r2) {
			if (c[p1] != c[p2]) ans += r1;
			r2 -= r1;
			p1++, r1 = a[p1];
		} else {
			if (c[p1] != c[p2]) ans += r2;
			r1 -= r2;
			p2--, r2 = a[p2];
		}
	}
	cout << ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

/*
亭中梨花谢又一年
立清宵 月华撒空阶
梦里笙箫奏旧乐
梦醒泪染胭脂面
小重山 念一遍又一遍 

闻 更漏咽
频教前尘辞长夜
久无眠 深坐对宫檐
多情最是春亭雪 年年落满离人怨
雪涛笺 上言若如初见

这一世 太漫长却止步咫尺天涯间
谁仍记 那梨花若雪时节
我心匪石不可转 我心匪席不可卷
空凝眸 情字深浅无解 
*/
