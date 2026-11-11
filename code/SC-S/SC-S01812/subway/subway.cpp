#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

int n,c,m,d,q;
ll W[500010],tot1[410][2],dis[1010],Dis[1010][1010];
bool vis[1010];
ll g1[410][410]; //24分 
map<int,long long>mp1,mp2; //8分
vector<pair<ll,int> >g[1010]; 

void dijkstra(int s,int en){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,int> >q;
	q.push({0,s});
	dis[s]=0;
	for(int i=1;i<=m;i++){
		ll minn = 1e18,id = 0;
		int u = q.top().second; q.pop();	
		if(vis[u])continue;
		vis[u] = 1;
		for(int v=1;v<=m;v++){
			if(g1[u][v]==0x3f3f3f3f)continue;
			if(vis[v])continue;
			if(dis[u]+g1[u][v]<dis[v]){
				dis[v] = dis[u]+g1[u][v];
				q.push({-dis[v],v});
			}
		}
	} 
}

void dijk(int s){
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,int> >q;
	Dis[s][s] = 0; q.push({0,s});
	while(!q.empty()){
		int u=q.top().second; q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i].first,w = g[u][i].second;
			if(vis[v])continue;
			if(Dis[v][s]>Dis[u][s]+w){
				Dis[v][s] = Dis[u][s]+w;
				q.push({-Dis[v][s],v});
			}
		}
	}
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&W[i]);
	if(c<=6){ 
		memset(g1,0x3f,sizeof g1);
		for(int t=1;t<=n;t++){
			int k; scanf("%d",&k);
			for(int i=1;i<=k;i++){
				scanf("%lld%lld",&tot1[i][0],&tot1[i][1]);
			}
			for(int i=1;i<=k;i++){
				for(int j=i+1;j<=k;j++){
					ll u=tot1[i][0],v=tot1[j][0]; ll w=tot1[i][1]+tot1[j][1];
					g1[u][v] = g1[v][u] = min(g1[u][v],w);
				}
			}
		}
		while(q--){
			int u,v; cin>>u>>v;
			dijkstra(u,v);
			printf("%lld\n",W[u]+W[v]+dis[v]); 
		}		
	}else if(c<=11){
		for(int t=1;t<=n;t++){
			int k; cin>>k;
			if(k==1){
				int u,w; cin>>u>>w; 
			}else{
				int u,v,w1,w2; cin>>u>>w1>>v>>w2; 
				g[u].push_back({v,w1+w2});
				g[v].push_back({u,w1+w2}); 
			}
		}
		memset(Dis,0x3f,sizeof(Dis));
		for(int i=1;i<=m;i++)dijk(i);
		while(q--){
			int u,v; cin>>u>>v;
			printf("%lld\n",W[u]+W[v]+Dis[u][v]); 
		}
	}else if(c==20||c==21){
		int k; scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int u; ll w; scanf("%d%lld",&u,&w);
			mp1[u] = w;
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int u; ll w; scanf("%d%lld",&u,&w);
			mp2[u] = w;
		}
		ll minn=0x3f3f3f3f;
		for(int i=1;i<=m;i++){
			if(mp1[i]&&mp2[i])minn=min(minn,mp1[i]+mp2[i]);
		}
		while(q--){
			int u,v; cin>>u>>v;
			ll ans=0x3f3f3f3f;
			if(mp1[u]&&mp1[v])ans = min(ans,mp1[u]+mp1[v]);
			if(mp2[u]&&mp2[v])ans = min(ans,mp2[u]+mp2[v]);
			if(mp1[u]&&mp2[v])ans = min(ans,mp1[u]+minn+mp2[v]);
			if(mp1[v]&&mp2[u])ans = min(ans,mp2[u]+minn+mp1[v]);
			printf("%lld\n",ans+W[u]+W[v]);
		}
	} 
	return 0;
} 