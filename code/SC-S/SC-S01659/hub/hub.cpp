#include<bits/stdc++.h>
#define LoveFurina ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define F(x, l, r) for(int x = l; x <= r; ++x)
#define B(x, r, l) for(int x = r; x >= l; --x)
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;

const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int c, t;
int n, k;
vector<int> adj[N];
int p[N], f[N];

inline void init() {
	F (i, 1, n) adj[i].clear();
}

inline void dfs1(int u, int fa, int r) {
	p[u] = r;
	for (int &v : adj[u]) {
		if (v == fa || f[v] || p[v]) continue;
		dfs1(v, u, r);
	}
}

inline int dfs2(int u, int fa) {
	if (f[u] != INF) return f[u];
	for (int &v : adj[u]) {
		if (v == fa) continue;
		f[u] = min(f[u], dfs2(v, u) + 1);
	}
	return f[u];
}

inline void Subtask_1_2_3() {
	int ans = INF;
	F (mask, 0, (1 << n) - 1) {
		if (__builtin_popcount(mask) != k) continue;
		F (i, 1, n) {
			p[i] = 0;
			f[i] = (mask >> i - 1) & 1 ? 0 : INF;
		}
		
		int tot = 0;
		F (i, 1, n) if (!f[i] && !p[i]) dfs1(i, 0, ++tot);
		if (tot > 2) continue;
		
		int cur = 0;
		F (i, 1, n) cur = max(cur, dfs2(i, 0));
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}

inline void Subtask_13_14() {
	n = (n - 1) / 2 - k;
	cout << (n + 3) / 4 + 1 << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	LoveFurina;
	
	cin >> c >> t;
	while (t--) {
		init(); cin >> n >> k;
		F (i, 1, n - 1) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		} 
		
		if (n <= 10) Subtask_1_2_3();
		else Subtask_13_14();
	}
	
return 0;
}
// 关注 luogu @DanseSolo 谢谢 awa 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 你不会以为我会无聊到四份代码都只写相同的一句注释吧？
// 真的假的呀？ 
// 
// 额……不过好像也没什么可以说的…… 
// 噢对对对，请来看我的 -S 游记谢谢，虽然可能也没什么意思就是了，不过点个赞再走嘛 awa 
// 这次的 -S 又考的非常非常烂，真的能有 1= 线吗 Qw
// 好像学了 15 个月的 OI 也没有进步多少嘛……
// 可是我不想退役啊……
// 我认为停课在机房打游戏看视频是非常快乐的，每天交几篇题解或者 AI 代码就可以敷衍过去
// 不过其实并没有这么干过（
// 总之总之，祝大家前途顺利吧 
// 我的舞台剧，也差不多要落幕了呢…… 
// 
// “生命如同戏剧，你永远无法知道转折出现在哪一篇章” 
// “世间的奇遇之所以存在，就是为了给世人带来转机 ” 