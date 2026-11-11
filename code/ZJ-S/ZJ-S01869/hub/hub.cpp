#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,T,n,k;
vector<int>g[N];
int dep1[N],dep2[N];
void dfs(int u,int fa,int *dep){
	dep[u]=dep[fa]+1;
	for(int v:g[u])
		if(v!=fa)dfs(v,u,dep);
}
bool check(int ans){
	
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
		dep1[i]=dep2[i]=0;
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,dep1);
	int mx1=0;
	for(int i=1;i<=n;i++)
		if(dep1[i]>dep1[mx1])mx1=i;
	dfs(mx1,0,dep2);
	int mx2=0;
	for(int i=1;i<=n;i++)
		if(dep2[i]>dep2[mx2])mx2=i;
	int mid1=dep2[mx2]/2,mid2=dep2[mx2]/2+1;
	
}
bool choose[N];
int dis[N];
void dfs1(int u,int fa){
	dis[u]=0;
	for(int v:g[u])
		if(v!=fa&&choose[v])
			dfs1(v,u);
}
void dfs2(int u,int fa){
	dis[u]=min(dis[u],dis[fa]+1);
	for(int v:g[u])
		if(v!=fa)
			dfs2(v,u);
}
void solve1(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=N;
	for(int i=0;i<(1<<n);i++){	
		if(__builtin_popcount(i)>k)continue;
		for(int j=0;j<n;j++)
			choose[j+1]=(i>>j)&1;
		int cnt=0;
		for(int i=1;i<=n;i++)dis[i]=N;
		bool ok=1;
		for(int i=1;i<=n;i++){
			if(choose[i]&&dis[i]==N){
				dfs1(i,0);
				if(++cnt>2){
					ok=0;
					break;
				}
			}
		}
		if(!ok)continue;
		for(int i=1;i<=n;i++)
			if(choose[i])
				dfs2(i,0);
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
		ans=min(ans,mx);
	}
	cout<<ans<<'\n';
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)solve1();
	return 0;
}
/*
二分答案，求出树的中心，在直径上往中心两边找到两个最远的点使得dis<=2*ans+1
然后贪心地从这两个点开始bfs往连通块里加点，优先加离叶子远的
不知道这个贪心对不对，并且有可能TLE 
还剩30min，感觉调不出来，那就先打1~3的子集枚举部分分 
还剩10min，不写了 
18:23 15pts
*/ 
