#include <bits/stdc++.h>

using namespace std;

/*
subtask2:
我们把完全图建出来，然后跑 n 次单源最短路
在做单源最短路时，顺便做最短路计数就好了
由于关心恰好有 2 条，所以 >= 3 条我们用统一的标志就行了，防止溢出
计算量大约是 300 * 1e5 * log(1e5)，好像有点爆了

注意到一个事情，由于要求最短路，所以假如是 u -> v, u < v
那么尽量往右跳肯定是优的，跨过了 v 也没关系，跨过了就相当于是到 v 了
折返一定不是最短的 
那么感觉会是一个数据结构的计数题？ 
我们把每个点尽力往右跳的边处理出来，倍增一下

不，不要先想倍增，我们连 n <= 5000 都不会呢
考虑一下 5000 怎么做
大概就是，枚举点对，然后快速判断是否是好的
如何快速判断？
首先我们应该不难求出来，从 u 到 v 得跳多少次, u <= v
设 jump[u][i] 表示从 u 往右尽力跳 i 次，最多能跳到哪儿
需要求最小的 i，使得 jump[u][i] >= v
jump[u][0] = u 
这个东西二分或者倍增应该都不难搞
求出来最小步数了，咋知道恰好有 2 条路呢？
现在只知道肯定有一条路了
恰好有 2 条很难受，能判断是否 >= 3 条吗？
稍等，我感觉 O(n^2) 有搞头
我枚举 u，然后从 v = u + 1 开始枚举 v
甚至于 u 我是从大到小枚举的
然后我维护一下，cnt[u][v] 表示从 u 到 v 的最短路有多少条，>= 3 按 3 算
len[u][v] 表示 u 到 v 的最短路长度 
如果我想算 cnt[u][v]，已知了 cnt[u][v - 1...u + 1]，怎么做？
考虑 k，如果 len[u][v] = len[u][k] + 1，且 k 能一步到 v 
那么 cnt[u][v] += cnt[u][k]
那么问题又来了，len[u][v] 咋求
首先一段肯定是 len[u][v] = 1，然后 u 一次跳不到 v，只能跳到 v - 1 了
那么就再从 v - 1 开始算，右边和自己距离 <= d 的就在 len[u][v - 1] 的基础上 + 1
维护一个 last 就行了
现在的问题是，cnt[u][v] 的计算能不能快一些，现在得枚举 k 的
我们好像可以维护一个 cnt 的前缀和
注意到 k 似乎是单调往右走的 
注意到可能不连通 
 
对于特殊性质 A


对于特殊性质 B
意思是我最多走 2 步就能从一个点走到任何一个其他点
走 1 步的显然只能是唯一的路径了
所以好对只能考虑走 2 步的路径
好像我枚举 u，假如 u 往右一步最多走到 x 位置
我们似乎是要做一个区间求交
考虑 u 最多跳到 x，t 最多跳到 y
其中 u < t 
考虑 [u, x] 和 [t, y] 的交集
交集恰好为 2 则 OK
这个也是单调的 

对于特殊性质 C 
*/

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef unsigned long long ULL;

const int N = 2e6 + 10;
const LL INFLL = 3e18;

LL n, d, x[N];

namespace subtask_5000 {
	const int M = 5010;
	
	// 最小步数 
	int len[M][M];
	// 最小步数的方案 
	int cnt[M][M];
	LL sum[M];
	
	void solve() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				len[i][j] = n + 1; // 压根不连通 
			}
			len[i][i] = 0;
		} 
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cnt[i][j] = 0;
			}
			cnt[i][i] = 1;
		}
		
		LL res = 0;
		for (int u = 1; u <= n; u++) {
			int last = u, last_len = 0;
			for (int v = u + 1; v <= n; v++) {
				if (x[v] - x[last] <= d) {
					len[u][v] = last_len + 1;
				} else {
					last = v - 1;
					last_len++;
					// 注意，从 v - 1 可能也飞不到 v 
					if (x[v] - x[last] <= d) {
						len[u][v] = last_len + 1;
					} else {
						// 不连通 
						break;
					}
				}
			}
			
			for (int v = u - 1; v <= n; v++) {
				sum[v] = 0;
			}
			sum[u] = cnt[u][u];
			
			int l = u, r = u;
			for (int v = u + 1; v <= n; v++) {
				// 不连通就不看了 
				if (len[u][v] == n + 1) {
					break;
				}
				
				// 左端点保证一步跳到 
				while (l < v && x[v] - x[l] > d) {
					l++;
				}
				
				r = max(l, r);
				// 右端点保证 len[u][r] + 1 == len[u][v]
				while (r < v && len[u][r] + 1 == len[u][v]) {
					r++;
				}
				r--;
				
				// [l, r] 内的都能贡献
				cnt[u][v] = sum[r] - sum[l - 1];
				if (cnt[u][v] >= 3) {
					cnt[u][v] = 3;
				} 
				
				sum[v] = sum[v - 1] + cnt[u][v];
			}
		}
		
		for (int u = 1; u <= n; u++) {
			for (int v = u + 1; v <= n; v++) {
				if (cnt[u][v] == 2) {
					res++;
				}
			}
		}
		
		cout << res << "\n"; 
	}
}

namespace subtask_b {
	
	void solve() {
		vector<PII> segs;
		int v = 1;
		for (int u = 1; u <= n; u++) {
			while (v <= n && x[v] - x[u] <= d) {
				v++;
			}
			
			v--;
			segs.push_back({u, v});
		}
		
		vector<PII> rev_segs;
		v = n;
		for (int u = n; u >= 1; u--) {
			while (v > 0 && x[u] - x[v] <= d) {
				v--;
			}
			v++;
			rev_segs.push_back({v, u});
		}
		reverse(rev_segs.begin(), rev_segs.end());
		
		int l = 0, r = 0;
		LL res = 0;
		for (int i = 0; i < segs.size(); i++) {
			int v = segs[i].second;
			while ((l < rev_segs.size()) && (v - rev_segs[l].first + 1 > 2)) {
				l++;
			}
			while ((l < rev_segs.size()) && (rev_segs[l].second <= v)) {
				l++;
			}
			r = max(l, r);
			while ((r < rev_segs.size()) && (v - rev_segs[r].first + 1 == 2)) {
				r++;
			}
			r--;
			
			if (v - rev_segs[l].first + 1 == 2) {
				res += r - l + 1;
			}
		}
		
		cout << res << "\n";
	}
}

void solve() {
	cin >> n >> d;
	bool is_b = false;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (x[i] - x[1] <= d && x[n] - x[i] <= d) {
			is_b = true;
		}
	}
	
	if (is_b) {
		subtask_b::solve();
	} else {
		subtask_5000::solve();
	}
}

int main() {
	#ifndef LOCAL_TEST
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1, c;
	cin >> c >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
} 
