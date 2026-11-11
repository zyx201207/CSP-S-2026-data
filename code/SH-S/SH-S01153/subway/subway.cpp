#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=500005;
struct E{
	ll u,v;
};
struct point{
	ll way,l,r,w;
};
ll cc,n,m,d,q;
//q->多测数 
ll w[M],k[505];
//w->进出站时间
//k[i]->第i条线过几站 
vector<E>g[505];
//g[i][j]第i条线j站的站下标，出站台时间 
ll x,y;
ll ans=1e18;
bool vis[15];
vector<point>p[15];
//p[i]那些线路经过站点i 
void dfs(ll nw,ll t,ll nwy){
	if(nw==y){
		for(int i=0;i<p[nw].size();i++){
			if(p[nw][i].way==nwy) {
				t+=p[nw][i].w;break;
			}
		}
		ans=min(ans,t); return ;
    }
	for(int i=0;i<p[nw].size();i++){
		int lef=p[nw][i].l,rgt=p[nw][i].r;
		if(!vis[lef]){
			vis[lef]=1;
			for(int j=0;j<p[lef].size();j++){
				if(p[lef][j].way==nwy) dfs(lef,t,nwy);
				else vis[lef]=0,dfs(lef,t+p[lef][j].w,p[lef][j].way);
			}
			vis[lef]=0;
		}
		if(!vis[rgt]){
			vis[rgt]=1;
			for(int j=0;j<p[rgt].size();j++){
				if(p[rgt][j].way==nwy) dfs(rgt,t,nwy);
				else vis[rgt]=0,dfs(lef,t+p[rgt][j].w,p[rgt][j].way);
			}
			vis[rgt]=0;
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&cc,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k[i];
		scanf("%lld",&k[i]);
		g[i].push_back({-1,1e18});
		for(int j=1;j<=k[i];j++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			g[i].push_back({u,v});
		}
		g[i].push_back({-1,1e18});
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			p[g[i][j].u].push_back({i,g[i][j-1].u,g[i][j+1].u,g[i][j].v});
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		if(n==3&&m<=10){
		ans=1e18;for(int i=0;i<=10;i++) vis[i]=0;			
			for(int i=0;i<p[x].size();i++){
				dfs(x,w[x]+p[x][i].w,p[x][i].way);
			}
			cout<<ans+w[y]<<endl;
		}
	}
	return 0;
	//解注释！！！！！！！ 
	//开long long !!!
	//ans=w[x]+w[y]+换乘时进出站台时间+进出站台时间 
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3

*/
	
