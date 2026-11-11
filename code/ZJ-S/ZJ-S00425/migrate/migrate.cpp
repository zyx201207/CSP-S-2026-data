#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, x[2000002], ans, cnt, minn;
void dfs(int p, int end, int step) {
	if (p == end) {
		if (step < minn)cnt = 1, minn = step;
		else cnt++;
		return;
	}
	for (int i = p + 1; i <= end; i++)
		if (x[i] - x[p] <= d)dfs(i, end, step + 1);
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	if (n <= 9) {
			while (t--) {
				memset(x, 0, sizeof x), ans = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> x[i];
			for (int u = 1; u < n; u++)
				for (int v = u + 1; v <= n; v++) {
					cnt = 0, minn = 1e18;
					dfs(u, v, 0);
					if (cnt == 2)ans++;
				}
			cout << ans << '\n';
		}
	}
	
	return 0;
}

/*
钟声响起归家的讯号
在他生命里
仿佛带点唏嘘
黑色肌肤给他的意义 
是一生奉献
肤色斗争中

年月把拥有变作失去
疲倦的双眼带着期望

今天只有残留的躯壳
迎接光辉岁月
风雨中抱紧自由
一生经过彷徨的挣扎
自信可改变未来
问谁又能做到

可否不分肤色的界限
愿这土地里
不分你我高低
缤纷色彩闪出的绚丽
是因它没有
分开每种色彩

年月把拥有变作失去
疲倦的双眼带着期望

今天只有残留的躯壳
迎接光辉岁月
风雨中抱紧自由
一生经过彷徨的挣扎
自信可改变未来
问谁又能做到

今天只有残留的躯壳
迎接光辉岁月
风雨中抱紧自由
一生经过彷徨的挣扎
自信可改变未来
问谁又能做到

今天只有残留的躯壳
迎接光辉岁月
风雨中抱紧自由
一生经过彷徨的挣扎
自信可改变未来
                      -- Beyond 《光辉岁月》
致屏幕前的你 
*/ 
