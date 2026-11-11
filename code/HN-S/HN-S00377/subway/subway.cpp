#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
ll c,n,m,d,q;
ll w[N],dis[M][M],vis[M];
struct node{ll v,w;};
vector<node> vc[N],g[M];
void dij(ll x){
	memset(vis,0,sizeof vis);
	priority_queue<pair<ll,ll> > q;
	q.push({0,x});
	while(q.size()){
		ll id=q.top().second,val=-q.top().first;
		q.pop();
		if(vis[id]==1)continue;
		vis[id]=1;
		dis[id][x]=dis[x][id]=min(dis[x][id],val);
		for(ll i=0;i<g[id].size();i++){
			ll to=g[id][i].v,w=g[id][i].w;
			if(vis[to]==0){
				q.push({-dis[x][id]-w,to});
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	memset(dis,0x3f,sizeof dis); 
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		int kk;scanf("%d",&kk);
		w[i]=kk;
	}
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			int x,v;scanf("%d%d",&x,&v);
			vc[x].push_back({i,v});
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<vc[i].size();j++){
			for(ll t=j+1;t<vc[i].size();t++){
				ll x=vc[i][j].v,y=vc[i][t].v;
				dis[x][y]=dis[y][x]=min(vc[i][j].w+vc[i][t].w,dis[x][y]);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(dis[i][j]!=0x3f3f3f3f3f3f3f3f){
				g[i].push_back({j,dis[i][j]});
				g[j].push_back({i,dis[i][j]});
			}
		}
	}
	for(ll i=1;i<=n;i++){
		dij(i);
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(ll i=0;i<vc[x].size();i++){
			for(ll j=0;j<vc[y].size();j++){
				ans=min((ll)ans,(ll)dis[vc[x][i].v][vc[y][j].v]+vc[x][i].w+vc[y][j].w);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
20 22
-70 -63 -56 -49 -42 -35 -28 -21 -14 -7 0 7 14 21 28 35 42 49 56 63
*/
