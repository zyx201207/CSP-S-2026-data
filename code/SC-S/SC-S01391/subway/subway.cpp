# include <bits/stdc++.h>
# define int LL
# define fr front
# define fir first
# define sec second
# define vec vector
# define pb push_back
# define lb lower_bound
# define ub upper_bound
# define all(x) x.begin(), x.end()
# define mem(a, b) memset(a, b, sizeof(a))

# define ls(p) (p << 1)
# define rs(p) (p << 1 | 1)
# define lson ls(p), l, mid
# define rson rs(p), mid + 1, r

# define sqr(x) ((x) * (x))
# define geti(x, i) (((x) >> (i)) & 1)
# define set1(x, i) ((x) | (1 << (i)))
# define set0(x, i) ((x) & (~(1 << (i))))

# define each1(x, a) for(auto x : a)
# define each2(x, a) for(auto &x : a)
# define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
# define pre(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;

using DB = double;
using LL = long long;
using LDB = long double;
using PII = pair<int, int>;
using ULL = unsigned long long;

const int N = 5e2 + 10, M = 5e5 + 10, Q = 1e5 + 10;
const int INF1 = 0x3f3f3f3f, INF2 = INT_MAX;
const LL INF3 = (LL)1e18, INF4 = 0x3f3f3f3f3f3f3f3f, INF5 = LLONG_MAX;

int sub, n, m, d, q, ans;
int w[N][N], dis[N][N], falcons[M];

vec<int> line[M];
vec<PII> e[M];

bitset<N> vis;

/*
没秒掉但是也不是很慌，才过一个小时
看了一下B性质，大概是说由于每个站最多有20条线路经过，并且T还是相等的
所以我肯定是经过的线路越少越好
而线路最多是500，我就可以记一下每个点可以到哪些站，图联通
诶
能不能开一个线路与线路两两之间的最短路
就是我从i线路到j线路最少走的时间
询问就变成了 q * 20 * 20 = 4e7
2500 * 最短路大约 m \log m
怎么是2*10^9，怎么只有1s，没事比一开始好了 
欸
每个点最多20条线
两两组合
最多是C(20, 2)=190条直接连两个线路的边
每个点都处理刚好200*500000=10^8
而且这些边都是可以存在500*500的矩阵里面的
只存两两之间最短的边就可以了
随便跑最短路
时间和脑力复杂度瓶颈在于想到直接处理两个线路
四点想完，开写 
等下最终的答案是什么呢？
x->y的整个路线
第一个线路是i，肯定和x相邻
最后一个线路是j，肯定和y相邻
枚举i, j
dis[i][j]+x到i的距离+y到j的距离
*/

void dijkstra(int s){
	priority_queue<PII, vec<PII>, greater<PII>> heap;
	vis.reset();
	heap.push({dis[s][s] = 0, s});
	
	while(!heap.empty()){
		int u = heap.top().sec;
		heap.pop();
		if(vis[u]) continue;
		vis[u] = true;
		
		rep(v, 1, n){
			if(vis[v] || dis[s][v] <= dis[s][u] + w[u][v]) continue;
			heap.push({dis[s][v] = dis[s][u] + w[u][v], v});
		}
	}
}

signed main(){
//	freopen("subway7.in", "r", stdin);
//	freopen("my.out", "w", stdout);
//# ifndef LOCAL
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//# endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	mem(w, 0x3f);
	mem(dis, 0x3f);
	cin >> sub >> n >> m >> d >> q;
	rep(i, 1, m) cin >> falcons[i];
	rep(i, 1, n){
		int k, a, t;
		cin >> k;
		rep(j, 1, k){
			cin >> a >> t;
			e[a].pb({i, t});
		}
	}
	rep(u, 1, m){
		rep(i, 0, (int)e[u].size() - 1){
			rep(j, i + 1, (int)e[u].size() - 1){
				w[e[u][i].fir][e[u][j].fir] = min(w[e[u][i].fir][e[u][j].fir], e[u][i].sec + e[u][j].sec);
				w[e[u][j].fir][e[u][i].fir] = min(w[e[u][j].fir][e[u][i].fir], e[u][i].sec + e[u][j].sec);
			}
		}
	}
	rep(i, 1, n) dijkstra(i);
	int x, y;
	while(q --){
		ans = INF5;
		cin >> x >> y;
		rep(i, 0, (int)e[x].size() - 1){
			rep(j, 0, (int)e[y].size() - 1){
				ans = min(ans, dis[e[x][i].fir][e[y][j].fir] + e[x][i].sec + e[y][j].sec);
			}
		}
		
		cout << ans + falcons[x] + falcons[y] << "\n";
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/