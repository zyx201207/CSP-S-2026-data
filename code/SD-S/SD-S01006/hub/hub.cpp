#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int INF = 1e9;
int c,t,n,k,u,v,tim,vis[N],dep[N],p[N];
int st[N][23];
vector<int> g[N],d,e;
void DFS(int u,int fa) {
	st[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(auto v : g[u]) {
		if(v == fa) continue;
		DFS(v,u);
	} 
}
void init(){
	for(int j = 1;j <= 20;j ++) {
		for(int i = 1;i <= n;i ++) {
			st[i][j] = st[st[i][j - 1]][j - 1];
		}
	}
}
int lca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	for(int i = 20;i >= 0;i --) {
		if((dep[u] - dep[v]) >= (1ll << i)) u = st[u][i];
	}
	if(u == v) return u;
	for(int i = 20;i >= 0;i --) {
		if(st[u][i] != st[v][i]) {
			u = st[u][i];
			v = st[v][i];
		}
	}
	return st[u][0];
}
int dist(int u,int v) {
//	cout << u << " " << v << " " << lca(u,v) << "\n";
//	cout << dep[u] << " " << dep[v] << " " << dep[lca(u,v)] << "\n";
	return dep[u] + dep[v] - 2 * dep[lca(u,v)];
}
void dfs(int u,int fa) {
	for(auto v : g[u]) {
		if(v != fa && p[v] == tim){
			vis[v] = tim;
			dfs(v,u);
		}
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t --) {
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i ++) g[i].clear();
		for(int i = 1;i < n;i ++) {
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= 20;j ++) st[i][j] = 0;
		}
		int ans = INF;
		DFS(1,0);
		init();
		for(int S = 0;S < (1 << n);++S) {
			int cnt = 0;
			d.clear();
			e.clear();	
			++tim;
			for(int i = 1;i <= n;i ++) {
				if(S & (1 << (i - 1))) cnt ++,d.push_back(i),p[i] = tim;
				else e.push_back(i);
			}
			if(cnt != k) continue;
			cnt = 0;
			for(auto v : d) {
				if(vis[v] != tim) {
					cnt ++;
					dfs(v,0);
				}
			}
			if(cnt >= 3) continue;
			int res = 0;
			for(auto u : e) {
				int sum = INF;
				for(auto v : d) {
					sum = min(sum,dist(u,v));
				}
				res = max(res,sum);
			}
			ans = min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
我的 luogu 名是 DF_G，欢迎壶关 
我 dijkstra 的优先队列忘记如何拼写了，于是用 set 代替，但是常数会加好多。 
上一场 J 组的最后一个题我填充了大量的废话，看到这一句话的可以找来看
上一场的最后一道题可能因为调试的时候忘记删除","导致爆零。
这一场估分是可悲的 100+[32,44]+24+15=[171,183] 我拉完了
1= 我觉得很悬，第二个应该是分层图最短路，Mx2013 大神应该能够干掉。应该有一车人能过
这一次为什么 CCF 出了三道图论啊恶心坏了 我最不喜欢图论了
记得有一次模拟赛 黄青紫黑，前三道是 DP，我说 CCF 绝对不会偏科。
但是感谢 CCF 给我的机会。我只是一个七年级的废物，能够在考场上与很多高中大佬同台竞技已是荣幸
这个比赛，应该是 黄青紫紫 吧。
不管则么样，我场不了青，本质废物。
希望能 J 1=，S 1= 这样就有蓝钩了 不然我现在连一个钩子都没有
膜拜一下大神 zpy.
今天没有测运势，希望是大吉。老天保佑我能考好。祖先保佑。
孔子保佑。鲁迅保佑。图灵保佑。欧拉保佑。 
*/
