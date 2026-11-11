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

const int N = 5e3 + 10;
const int INF1 = 0x3f3f3f3f, INF2 = INT_MAX;
const LL INF3 = (LL)1e18, INF4 = 0x3f3f3f3f3f3f3f3f, INF5 = LLONG_MAX;

int n, d, ans;
int x[N], dis[N], cnt[N];

vec<int> e[N];

bitset<N> vis;

/*
显然可以钦定x_u <= x_v，反正求的是无序对
发现经过的点i肯定满足 x_u <= x_i <= x_v，否则不是最短的
相当于是最短路不会走回头路 
有了这个性质可以有一个暴力
直接按照题意，给x_v - x_u <= d的从u到v连边
那从u为源点跑一个最短路计数
碰到最短路数是2的就加起来
n * (n + m) log n的吧
边数最坏是n^2级别的
理论就是n^3 log n
尴尬的24pts，其实感觉没那么慢，因为如果当前最短点u的cnt_u已经大于2了
那么后面的肯定都大于2了，因为这个东西能继承，关键是如果他是n^2的图
cnt可以很快超过2 
应该能有40pts 

我决定最后40分钟打T4的暴力
现在还有40分钟用来想T3 
冲波正解，感觉像是一个 DP

A是等差数列
如果差值大于d显然为0
=d的话也是0
只有看小于d的了
你发现如果d < 两倍的差值，还是0，因为每次只能往前走一步 
比如两倍差值 <= d < 三倍差值
你发现自己右边第一第二个点的方案还是1，但是第三个点会恰好有两个方案 
第四个是1个方案，第五个就是3个方案了，不用看了
但是只要三倍差值 <= d，那么前几个都是1方案，到了第一个距离和自己大于d的，直接就变成 d/差值了
也就是等差数列只有2 <= d < 3才有解，这是好统计的
48pts
由于求的是两种方案的数量
你想一下能不能快速求呢
也就是一个点u，和右边的点v
如果v - u <= d，方案只能为1
然后考虑这种点处理完了的下一个 
如果这个点叫i
那么如果 [x_i - d, x_i - 1] 中恰好有两个点，方案数就是2了呀woc
如果只有一个点的话，他的方案也是1
如果0个点或者大于等于3个点直接起飞，贡献滚木
考虑i的方案为1或者2的时候
如果为 2，那么下一个点j必须满足 [x_j - d, x_j - 1] 这个范围只有 i 一个点才能产生贡献
那么也就是说如果我有一个点的方案是2了，后面的点p都得满足 [x_p - d, x_p - 1] 只有 p - 1 这个点才行
如果为 1，那么还是相同的形式，后面的第一个有贡献的点p要满足 [x_p - d, x_p - 1] 有两个点，否则方案还是 1
考虑预处理出来每个点i的 [x_i - d, x_i - 1] 的点的数量，二分即可 
我可以先二分找到第一个i使得 x_i - d > x_u
跳过那些 [x_i - d, x_i - 1] 只有一个点的数量
可以从后往前扫描处理一个nxt1数组，表示i这个位置下一个[x_j - d, x_j]包含点数不是1的j
直接 i = nxt1[i]
如果包含的不是2，（0，3，4，……）直接贡献滚木
如果恰好是2，那么又去找nxt1[i]，因为只要包含的是1方案就一直是2
nxt边界随便处理 
六点二十完蛋了思路假了 
原因是i会在[x_i - d, x_i - 1]中选择dis最小的
刚刚的分析只是一种情况罢了
真正的做法是[x_i - d, x_i - 1]中dis最小值的方案数总和为2
刚刚是一种情况
现在有没有别的情况
不会了
大暴力
还有10min 
*/ 

void dijkstra(int s){
	rep(i, s, n) dis[i] = INF4, cnt[i] = 0, vis[i] = false;
	cnt[s] = 1;
	priority_queue<PII, vec<PII>, greater<PII>> heap;
	heap.push({dis[s] = 0, s});
	while(!heap.empty()){
		int u = heap.top().sec;
		heap.pop();
		if(vis[u]) continue;
		vis[u] = true;
		each2(v, e[u]){
			if(vis[v] || dis[v] < dis[u] + 1) continue;
			if(dis[v] == dis[u] + 1){
				cnt[v] += cnt[u];
			}
			
			else{
				cnt[v] = cnt[u];
				heap.push({dis[v] = dis[u] + 1, v});
			}
		}
	}
}

void solve(){
	cin >> n >> d;
	ans = 0;
	rep(i, 1, n) cin >> x[i], e[i].clear();
	rep(i, 1, n - 1){
		rep(j, i + 1, n){
			if(x[i] + d >= x[j]){
				e[i].pb(j);
			}
		}
	}
	
	rep(i, 1, n){
		dijkstra(i);
		rep(j, i + 1, n){
			if(cnt[j] == 2) ans ++;
		}
	}
	
	cout << ans << "\n";
}

signed main(){
# ifndef LOCAL
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
# endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int sub, T;
	cin >> sub >> T;
	while(T --) solve();
	
	return 0;
}
/*
0 1
6 6
0 2 4 6 8 10

3

1
*/