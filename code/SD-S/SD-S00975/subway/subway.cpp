#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
const ll N=5e5+10;
const ll M=5e2+10;
ll c,n,m,d,q;
ll w[N];
vector<pair<ll,ll> > line[M];
vector<pair<ll,ll> > sta[N];
ll dis[M][M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		dis[i][i]=0;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			line[i].pb({a,t});
			sta[a].pb({i,t});
		}
	}
	
	for(int s=1;s<=m;s++){
		for(auto i:sta[s]){
			for(auto j:sta[s]){
				ll x=i.first,y=j.first;
				dis[x][y]=dis[y][x]=min(dis[x][y],i.second+j.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:sta[u]){
			for(auto j:sta[v]){
				ll x=i.first,y=j.first;
				ans=min(ans,dis[x][y]+i.second+j.second+w[u]+w[v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
d可能很重要 d<=20
地铁线数量n<=500 但是 q 巨大，考虑建图全源最短路？
地铁站数量m 5e5
直接建图时间复杂度 O((n+m)^3)

注意d<=20 n<=500，这是否启示我们不完全建图？ 建图应该要缩边
最后建出来的图很大可能只有n量级，随后跑弗洛伊德 
 
最多换乘 500 次，是否与这个可能有关

一个站点不会多次到达

nm 的复杂度卡卡能过吧 2.5e8 nm+qm 也能过吧 至少拿84够了 
 
是不是维护每个站点到每条线路需要的最短时间 空间不允许 

d<=20 说明每个点度数最多为 20，如果围绕 地铁站与地铁线建图，总共边数不超过 2e7 空间基本允许了？这个做法有可能是对的吧

但是这样还需要跑最短路 mst有关？

k_i 之和 <=5e5 这个也很重要 也就是说，换乘站不算多 两条不同地铁线的换乘方案数只有 2.5e5 同样很小

不会这么做吧
求出两条地铁线换乘方式的最小值，这个可以flyod跑 1.25e8
然后每个询问枚举开始地铁线、结束地铁线，这个是 20*20*1e5=4e7

可以过吧 
*/

