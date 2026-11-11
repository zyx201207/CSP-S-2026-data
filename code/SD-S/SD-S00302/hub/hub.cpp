//when you use deque or vector,
//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define mid (l+r>>1)
using namespace std;
const int N=1e6+2;
int _,T,n,m,ans,cut,p,q,dep[N],tax[N],f[N],fa[N];
vector<int> g[N];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
void dfs(int u) {
	dep[u]=dep[fa[u] ]+1;
	for (int v:g[u]) if (v^cut&&v^fa[u])
	fa[v]=u,dfs(v); if (dep[u]>dep[p]) p=u;
}
void dfs2(int u) {
	f[u]=0; for (int v:g[u]) if (v^cut&&v^fa[u])
	fa[v]=u,dfs2(v),f[u]=max(f[u],f[v]+1); if (fa[u]) tax[f[u] ]++;
}
int work(int x,int y)
{
	int cnt=1; memset(tax,0,4*n);
	cut=y,p=x,fa[x]=0,dfs(x),fa[q=p]=0,dfs(q);
	for (int i=dep[p]/2;i;i--) p=fa[p];
	fa[p]=0,dfs2(p);
	if (y) {
		cut=x,p=y,fa[y]=0,dfs(y),fa[q=p]=0,dfs(q);
		for (int i=dep[p]/2;i;i--) p=fa[p];
		fa[p]=0,dfs2(p),cnt++;
	}
	for (int i=n-1;~i;i--)
	if (cnt+tax[i]>m) return i+1;
	else cnt+=tax[i]; return 0;
}
namespace Subtask1 
{
	void main()
	{
		while (T--)
		{
			n=read(),m=read();
			for (int i=1;i<n;i++) {
				int x=read(),y=read();
				g[x].push_back(y),g[y].push_back(x);
			}
			ans=work(1,0);
			for (int x=1;x<=n;x++)
				for (int y:g[x]) if (x<y)
					ans=min(ans,work(x,y) );
			
			printf("%d\n",ans);
			for (int i=1;i<=n;i++) g[i].clear();
		}
	}
}
namespace Subtask2
{
	P f[N],F[N],pre[N],suf[N];
	P operator +(P a,int b) {
		return {a.first+b,a.second};
	}
	P operator +(P a,P b) {
		return {max(a.first,b.first),max({a.second,b.second,a.first+b.first})};
	}
	void dfs1(int u)
	{
		f[u]={0,0};
		for (int v:g[u]) {
			g[v].erase(find(range(g[v]),u) );
			dfs1(v),f[u]=f[u]+(f[v]+1);
		}
	}
	void dfs2(int u) {
		pre[0]=F[u]+1,suf[g[u].size()+1]={0,0};
		for (int i=1;i<=g[u].size();i++) pre[i]=pre[i-1]+(f[g[u][i-1] ]+1);
		for (int i=g[u].size();i;i--) suf[i]=suf[i+1]+(f[g[u][i-1] ]+1);
		for (int i=0;i<g[u].size();i++) F[g[u][i] ]=pre[i]+suf[i+2];
		for (int v:g[u]) dfs2(v);
	}
	void main()
	{
		while (T--)
		{
			n=read(),m=read();
			for (int i=1;i<n;i++) {
				int x=read(),y=read();
				g[x].push_back(y),g[y].push_back(x);
			}
			ans=work(1,0);
			fa[1]=0,dfs1(1),F[1].first=-1,dfs2(1);
			for (int i=2;i<=n;i++)
			ans=min(ans,max((f[i].second+1)/2,(F[i].second+1)/2) );
			printf("%d\n",ans);
			for (int i=1;i<=n;i++) g[i].clear();
		}
	}
}
namespace Subtask3
{
	void main()
	{
		while (T--)
		{
			n=read(),m=read();
			for (int i=1;i<n;i++) {
				int x=read(),y=read();
				g[x].push_back(y),g[y].push_back(x);
			}
			if (n>50) {
				ans=work(1,0);
				for (int i=max(n/4-3,1);i<=min(n/4+3,n/2);i++)
				ans=min(ans,work(i,i+1) ); printf("%d\n",ans);
			}
			else {
				ans=work(1,0);
				for (int x=1;x<=n;x++)
					for (int y:g[x]) if (x<y)
						ans=min(ans,work(x,y) );
				
				printf("%d\n",ans);
			} 
			for (int i=1;i<=n;i++) g[i].clear();
		}
	}
}
main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	_=read(),T=read();
	if (_<11) Subtask1::main();
	else if (_<13) Subtask2::main();
	else Subtask3::main();
	return 0;
}
/*
若只有一个连通块，那么应该包含直径中点 
两个连通块怎么做（注意需要特判一个连通块的情况），
应该存在一条边 (x,y)，使得 x 子树内都到 S1，y 子树内都到 S2
考虑二分答案 mid，然后枚举这条边，那么对于这个子树，连通块应该包含这个直径中点 
以这个点为根，选 x 当且仅当 x 子树内 x 的高度>=mid
那么不难做到 n^2，可以获得 50pts
感觉这条边也有说法啊，唉不清楚 
如果这条边不在原树直径上，那么子树补的直径就是整个树的直径
如果这条边在直径上，感觉分析这个没用啊，能不能直接做 
如果一条边不优，那么，感觉应该移动到答案更大的那边 
直接做即可 O(nlog^2 n)，可以获得不知道多少分， 
真的对吗，如果较大的那边， 
能不能更牛啊，比如说，去掉外层的二分？ 
感觉没有道理 
感觉正解应该能做到 O(n) check
考虑每个点 x 会对哪些边产生贡献，如果在这个点的 mid 邻域内割边，那么是不会产生贡献的
那么，需要存在一个点 y，使得 dis(x,y)>=mid（或 =y），且直径中点不在 x 到 y 的路径上 
把会做啊
割掉一条边后直径中点应该怎么移， 
终究还是只有入门组水平吗
[50,70]
感觉应该有很强的性质啊，否则 2e6 3s 根本不能做 
17:27 50pts
k=2怎么做，此时若两个连通块，则会贡献 (两个连通块的直径+1)/2
 
考察每个点的贡献，如果有至少三个子树的高度 >=x，那么肯定会产生贡献 
如果只有 <=1 个子树的高度 >=x，那么一定不会产生贡献 
也就是说，需要割在左边而直径中点在右边，还是不会做啊，不管了 
18:03 60pts
18:20 70pts
*/
