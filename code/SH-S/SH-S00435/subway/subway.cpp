#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=2e4+5;
ll c,n,m,d,q,mm[M],dis1[N][M+N],INF=1e18;
bool vis[N+M];
vector<pair<ll,ll> > g[N+M];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
inline ll read(){
	ll xx=0,sta=1;char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')sta=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){xx=xx*10+cc-'0';cc=getchar();}
	return xx*sta;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(ll i=1;i<=m;i++) mm[i]=read();
	for(ll i=1;i<=n;i++){
		ll k=read();
		for(ll j=1;j<=k;j++){
			ll vv=read(),ww=read();
			g[vv].push_back({M+i,ww});
			g[M+i].push_back({vv,ww});
		}
	}
	if(c==20 or c==21){
		ll dis[3][N+M];
		memset(dis,0x3f,sizeof(dis));
		for(ll i=1;i<=n;i++){
			while(!pq.empty()) pq.pop();
			memset(vis,false,sizeof(vis));
			dis[i][M+i]=0;
			pq.push({0,M+i});
			while(!pq.empty()){
				ll w=pq.top().first,u=pq.top().second;
				pq.pop();
				if(vis[u]) continue;
				vis[u]=true;
				for(ll j=0;j<g[u].size();j++){
					ll v=g[u][j].first,w=g[u][j].second;
					if(dis[i][v]>dis[i][u]+w){
						dis[i][v]=dis[i][u]+w;
						pq.push({dis[i][v],v});
					}
				}
			}
		}
		while(q--){
			ll xx1=read(),yy1=read(),ans=INF;
			for(ll i=1;i<=n;i++) ans=min(dis[i][xx1]+dis[i][yy1],ans);
			printf("%lld\n",ans+mm[xx1]+mm[yy1]);
		}
		return 0;
	}
	memset(dis1,0x3f,sizeof(dis1));
	for(ll i=1;i<=n;i++){
		while(!pq.empty()) pq.pop();
		memset(vis,false,sizeof(vis));
		dis1[i][M+i]=0;
		pq.push({0,M+i});
		while(!pq.empty()){
			ll w=pq.top().first,u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=true;
			for(ll j=0;j<g[u].size();j++){
				ll v=g[u][j].first,w=g[u][j].second;
				if(dis1[i][v]>dis1[i][u]+w){
					dis1[i][v]=dis1[i][u]+w;
					pq.push({dis1[i][v],v});
				}
			}
		}
	}
	while(q--){
		ll xx1=read(),yy1=read(),ans=INF;
		for(ll i=1;i<=n;i++) ans=min(dis1[i][xx1]+dis1[i][yy1],ans);
		printf("%lld\n",ans+mm[xx1]+mm[yy1]);
	}
	return 0;
}
