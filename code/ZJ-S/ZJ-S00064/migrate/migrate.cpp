// ？瞄了一眼 T3T4 怎么全是图论？！ 
// CCF 写图写啥了？！ 
// 我错了，第三题不是图论QAQ 
// 我是要冲 300+ 的人 ，这道应该是蓝以上的 dp 必须拿下！！！！
// 可以先 nlogn 预处理一下 
// n^2 还是简单的 但是我已经不会继续优化了QAQ 我要是再不优化就成大众分了！！！ 罢了罢了看 T4 
// woc，好像是乘法原理=2就可以！！！！这题好像是组合计数 DP！！！ 
// 好吧还是不会，拿个 48 跑路 
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
queue <int> q;
int c, t, n, m, a[N], mdis[N], cnt[N], dis[N]; 
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	if (c == 11 || c == 12) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		int tas = 1;
		for ( ; tas <= n; ++tas) if (a[tas] - a[1] > m) break ;
		--tas;
		long long ans = 0, jj = 0;
		for (int i = tas * 2; i <= n; ++i) {
			if (i % tas == 0) ++jj;
			ans += jj; 
		}
		printf("%lld", ans);
		return 0;
	}
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		long long ans = 0ll;
		for (int i = 1; i <= n; ++i) {
			q.push(i);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int i = u + 1; i <= n; ++i) {
					if (a[i] - a[u] > m) break ;
					if (dis[i] && dis[i] < dis[u] + 1) continue ;
					if (!dis[i]) dis[i] = dis[u] + 1, q.push(i);
					++cnt[i];
				} 
				if (cnt[u] == 2) ++ans;
				cnt[u] = dis[u] = 0;
			}
		} 
		printf("%lld\n", ans);
	}
	return 0;
}
