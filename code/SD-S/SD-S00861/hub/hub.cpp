#include<bits/stdc++.h>
bool Med;
#define rep(i,j,k) for(int i=(j);(i)<=(k);(i)++)
#define per(i,j,k) for(int i=(j);(i)>=(k);(i)--)
#define i64 long long
#define u64 unsigned long long
#define inf 0x3f3f3f3f
#define inf64 0x3f3f3f3f3f3f3f3fll
#define pb push_back
namespace Staque{
	template<typename T,typename U>inline bool gmax(T &x,const U &y){return x<y?(x=y,1):0;}
	template<typename T,typename U>inline bool gmin(T &x,const U &y){return x>y?(x=y,1):0;}
	void Freopen(){freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);}
}using namespace Staque;
const int N=2005;
int n,k,dist[N],g[N],vis[N],st[N];
std::vector<int> G[N];
void dfs(int u,int ff){
	for(auto v:G[u])if(v^ff){
		dist[v]=dist[u]+1,dfs(v,u);
	}
}
void dfs2(int u,int ff){
	st[u]=1;
	for(auto v:G[u])if(v^ff){
		if(vis[v])dfs2(v,u);
	}
}
void Init(){}
void testCase(){
	std::cin>>n>>k;
	rep(i,1,n-1){
		int x,y;std::cin>>x>>y;
		G[x].pb(y),G[y].pb(x);
	}
	dist[0]=-1;
	int d=inf;
	rep(i,1,(1<<n)-1){
		rep(j,1,n)g[j]=inf;
		int cc=0;
		rep(j,1,n)st[j]=vis[j]=0; 
		rep(j,1,n)if(i>>(j-1)&1)cc++,vis[j]=1;
		if(cc!=k)continue;
		int ccc=0;
		rep(j,1,n)if(i>>(j-1)&1){
			dist[j]=0,dfs(j,0);
			if(!st[j])dfs2(j,0),ccc++;
			rep(p,1,n)gmin(g[p],dist[p]);
//			std::cout<<"\n";
		}
		if(ccc>2)continue;
		int mx=0;
//		std::cout<<i<<':';
		rep(j,1,n)gmax(mx,g[j]);
//		std::cout<<"\n";
//		if(mx==1)std::cout<<i<<"::::::\n";
		gmin(d,mx);
	}
	std::cout<<d<<"\n";
	rep(i,1,n)G[i].clear();
}
bool Mst;
int main(){
	Freopen();
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	int TC=1,CC;
	std::cin>>CC>>TC;
	while(TC--)testCase();
	fprintf(stderr,"Memory:%.3lfMB\nTime:%.3lfs\n",(&Med-&Mst)/1048576.0,clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1 0 2 1 1 3 3 3 4 5
1 2 0 3 3 1 1 1 2 3
4 5 3 6 6 4 2 4 1 0
518:1 0 0 1 1 1 1 1 1 0

*/
