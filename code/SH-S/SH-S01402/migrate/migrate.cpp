/*
我们终于可以正眼看 T3 了woh
这题感觉有蓝或紫了。思考半个小时没结果就去 T4 看我比较好的数据结构
如果有间距 >d，分开考虑是显然的。否则互相两点之间必然可达 
首先必然不会先往反方向跳
其次我们可以考虑用数据结构去维护免得观察神秘性质
考虑扫描右端点维护左端点方法数
新增的贡献为旧区间内所有在 [x_i-d,x_i] 内的方法数之和，显然如果有大于 2 个可以直接 AFO（bushi
然后只需要考虑 1, 2, \ge 2。（不可能 0） 
因此感觉可以做成一个单调指针？ 
更仔细一点——但是统一用点数代表路径长度 
显然往左方法数单调不减 
如果区间内有两个以上的点，那么前驱^3及之前的所有点无效。前驱^2为2，前驱^1为1. 
如果区间内只有一个点，那么所有可以转移到这个点的 2 是 2，所有可以转移到这个点的 1 是 1，这个点是 1，其他无效 
如果区间内有两个点，那么所有可以同时转移到两个点的 1 是 2，所有可以转移到这两个点的 2 无效，所有只转移到前一个点 2 是 2，1 是 1，其他无效。
第二个点本身是 2，第一个点本身是 1. 
类似这种（虽然我好像在胡言乱语） 
怎么维护这个东西呢。我们做 2 个数，分别表示 \ge 2 的最后一个，2 的最后一个。 
然后应该是可以做到 O(1) 转移的，去在值域上维护一个单调指针 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr long long INF = 1e18;
void run() {
	// 多测用 vector，最省心
	int n, d;
	cin >> n >> d;
	vector<int> x(n + 1);
	for (int i = 1; i <= n; ++i) cin >> x[i];
	
	vector<int> cnt((n + 2) * (n + 2), 0), minlen((n + 2) * (n + 2), INF);
	int ptr = 1; // 区间内点 
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (ptr < i && x[i] - x[ptr] > d) ptr++;
		minlen[i * n + i] = 0; cnt[i * n + i] = 1;
		for (int k = ptr; k < i; ++k) {
			minlen[i * n + k] = 1;
			cnt[i * n + k] = 1;
		}
		for (int j = 1; j < ptr; ++j) {
			minlen[i * n + j] = minlen[(ptr * n) + j] + 1;
		}
		for (int j = 1; j < ptr; ++j) {
			for (int k = ptr; k < i; ++k) {
				if (minlen[i * n + j] == minlen[(k * n) + j] + 1) {
					cnt[i * n + j] += cnt[k * n + j];
				}
				else break;
			}
		}
		for (int j = 1; j < i; ++j) if (cnt[i * n + j] == 2) ans++;
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) run();
	return 0;
}
