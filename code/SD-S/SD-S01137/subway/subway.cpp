#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[1005];
ll k[1005];
ll dis[1005][1005];
ll edge[1005][1005];
ll t[1005];
ll a[1005];
ll vis[1005];
ll dist[1005];
ll c,n,m,d,q;
struct Node{
	ll u,dis;
	bool operator<(const Node &x)const{
		return dis>x.dis;
	}
}; 
void dijkstra(ll s){
	priority_queue<Node>pq;
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	vis[s]=1;
	pq.push({s,0});
	while(!pq.empty()){
		Node now=pq.top();pq.pop();
		for(ll i=1;i<=m;i++){
			if(dist[now.u]+edge[now.u][i]<dist[i]){
				dist[i]=dist[now.u]+edge[now.u][i];
				if(!vis[i]){
					vis[i]=1;
					pq.push({i,dist[i]});
				}
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	if(1){
		memset(dis,0x3f,sizeof dis);
		memset(edge,0x3f,sizeof edge);
		for(ll i=1;i<=m;i++){
			cin>>w[i];
			dis[i][i]=0;
		}
		for(ll i=1;i<=n;i++){
			cin>>k[i];
			for(ll j=1;j<=k[i];j++){
				cin>>a[j]>>t[j];
				//cerr<<a[j]<<" ";
			}
		//	cerr<<"\n";
			for(ll j=1;j<=k[i]-1;j++){
				for(ll e=j+1;e<=k[i];e++){
					edge[a[j]][a[e]]=min(edge[a[j]][a[e]],t[j]+t[e]);
					edge[a[e]][a[j]]=edge[a[j]][a[e]];
				}
			}
		}
//		for(ll i=1;i<=m;i++){
//			for(ll j=1;j<=m;j++){
//				if(dis[i][j]==dis[505][505])cerr<<-1<<" ";
//				else cerr<<edge[i][j]<<" ";
//			}
//			cerr<<"\n";
//		}
//		dijkstra(1);
//		for(ll j=1;j<=m;j++){
//			cout<<dist[j]<<" ";
//		}
		for(ll i=1;i<=m;i++){
			dijkstra(i);
			for(ll j=1;j<=m;j++){
				dis[i][j]=dist[j];
			}
		}
//		for(ll i=1;i<=m;i++){
//			for(ll j=1;j<=m;j++){
//				if(dis[i][j]==dis[505][505])cerr<<-1<<" ";
//				else cerr<<dis[i][j]<<" ";
//			}
//			cerr<<"\n";
//		}
		while(q--){
			ll u,v;
			cin>>u>>v;
			cout<<dis[u][v]+w[u]+w[v]<<"\n";
		}
	}
	return 0;
}


/*


7 3 3 2 1
0 0 0
2 1 3000 2 3000
2 1 1 3 1
2 3 1 2 1
3 1

*/

