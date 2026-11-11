#include<cstdio>
#include<algorithm> 
#include<vector>
const int MAXN = 15;
int c, T; 
int n, k;
std::vector<int> edge[MAXN];
int pre[MAXN], depth[MAXN], dfn[MAXN], hson[MAXN], size[MAXN], cnt;
void dfs1(int x)
{
	size[x] = 1, hson[x] = 0, dfn[x] = ++ cnt;
	for(int y : edge[x])
		if(y != pre[x])
		{
			pre[y] = x;
			depth[y] = depth[x] + 1;
			dfs1(y);
			size[x] += size[y];
			if(size[y] > size[hson[x]]) hson[x] = y;
		}
}
int top[MAXN];
void dfs2(int x)
{
	if(hson[x]) top[hson[x]] = top[x], dfs2(hson[x]);
	for(int y : edge[x])
		if(y != pre[x] && y != hson[x])
			top[y] = y, dfs2(y);
}
int LCA(int x, int y)
{
	while(true)
	{
		if(top[x] == top[y]) return depth[x] < depth[y] ? x : y;
		if(depth[top[x]] < depth[top[y]]) std::swap(x, y);
		x = pre[top[x]];
	}
}
int get_dist(int x, int y) {int l = LCA(x, y); return depth[x] - depth[l] + depth[y] - depth[l];}
int a[MAXN], m = 0;
int d[MAXN];
int ans = 0x3f3f3f3f;
bool vis[MAXN], f[MAXN];
void dfs3(int x)
{
	vis[x] = true;
	for(int y : edge[x]) if(f[y] && !vis[y]) dfs3(y); 
}
int get()
{
	for(int i = 1; i <= n; ++ i) vis[i] = false;
	int c = 0;
	for(int i = 1; i <= m; ++ i) if(!vis[a[i]]) dfs3(a[i]), c ++;
	return c;
}
void dfs()
{
	if(m > k) return ;
	if(m == k)
	{
		for(int i = 1; i <= n; ++ i) f[i] = false;
		for(int i = 1; i <= m; ++ i) f[a[i]] = true;
		int sum = get();
		if(sum > 2) return ;
		for(int i = 1; i <= n; ++ i) d[i] = 0x3f3f3f3f;
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= m; ++ j) d[i] = std::min(d[i], get_dist(i, a[j]));
		int R = 0;
		for(int i = 1; i <= n; ++ i) R = std::max(R, d[i]);
		ans = std::min(ans, R);
		return ;
	}
	for(int i = a[m] + 1; i <= n; ++ i) a[++ m] = i, dfs(), a[m --] = 0;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T --)
	{
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++ i) edge[i].resize(0), pre[i] = 0, depth[i] = 0, dfn[i] = 0, hson[i] = 0, size[i] = 0, top[i] = 0, a[i] = 0, d[i] = 0; cnt = 0; m = 0; ans = 0x3f3f3f3f;
		for(int i = 1; i < n; ++ i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		pre[1] = 0, depth[1] = 0, cnt = 0, dfs1(1);
		top[1] = 1, dfs2(1);
		dfs();
		printf("%d\n", ans);
	}
	return 0;
}
