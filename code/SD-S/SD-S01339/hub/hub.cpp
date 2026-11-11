#include<bits/stdc++.h>
#define int long long
using namespace std;
//多测不清空的是给 我清了
const int N=105,inf=0x3f3f3f3f3f3f3f3f;
int n,k,ans;
vector<int>G[N];
int dep[N],fa[N][25];
queue<int>q;
void bfs() {
	q.push(1);
	dep[1]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v:G[u]) {
			if(dep[v]) continue;
			dep[v]=dep[u]+1;
			fa[v][0]=u;
			q.push(v);
			for(int i=1; i<=20; ++i) {
				fa[v][i]=fa[fa[v][i-1]][i-1];
			}
		}
	}
}
int LCA(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20; i>=0; --i) {
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=20; i>=0; --i) {
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int dis(int x,int y) {
	return dep[x]+dep[y]-dep[LCA(x,y)]*2;
}
bool vis[N];
void dfs(int u) {
	vis[u]=1;
	for(auto v:G[u]) {
		if(!vis[v]) dfs(v);
	}
}
int solve() {
	//15分做法 2^n nlogn
	ans=inf;
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		G[i].clear();
		dep[i]=0;
		for(int j=0; j<=20; ++j) fa[i][j]=0;
	}
	for(int i=1; i<n; ++i) {
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	bfs();
	for(int s=0; s<(1<<n); ++s) {
		int res=0;
		int h[15],tot=0;
		int cnt=0;
		memset(vis,0,sizeof vis);
		for(int i=1; i<=n; ++i) {
			if(s>>(i-1)&1) h[++tot]=i;
			else vis[i]=1;
		}
		if(tot!=k) continue;
		for(int i=1; i<=tot; ++i) {
			if(!vis[h[i]]) {
				++cnt,dfs(h[i]);
			}
		}
		if(cnt>2) continue;
		for(int i=1; i<=n; ++i) {
			if(s>>(i-1)&1) continue;
			int d=inf;
			for(int u=1; u<=tot; ++u) {
				int j=h[u];
				d=min(d,dis(i,j));
			}
			res=max(res,d);
		}
		ans=min(ans,res);
	}
	return ans;
}
int solveA() {
	//10分 特殊性质A
	ans=inf;
	cin>>n>>k;
	for(int i=1; i<n; ++i) {
		int x,y;
		cin>>x>>y;
	}
	int m=n/2;
	if(k==n) return 0;
	if(k>=m) return 1;
	for(int c2=0; c2<=m-k; ++c2) {
		int c1=(m-k-c2+1)/2;
		int res=max(c1,(c2+1)/2)+1;
		ans=min(ans,res);
	}
	return ans;
}
/*
18:10 我现在会#7了 
这里需要使用dfn序上的线段树
这是给 写的，我不写
还是检查检查吧 
*/
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0);
	int c,T=1;
	cin>>c>>T;
	if(c<=3) while(T--) cout<<solve()<<"\n";
	if(c==13||c==14) while(T--) cout<<solveA()<<"\n";
	return 0;
}
/*
"默契无法伪造，我们同一种调调"
去年除了我之外还有一个人代码里出现了SD-S01020

我忘了去年的SD-S01020今年是多少号了
好像是SD-S01448还是SD-S01488来着

I think he must get 200+

RP++ 
*/
