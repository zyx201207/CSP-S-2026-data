#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
const ll INF=0x3f3f3f3f;
ll c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x[N],y[N];
/*struct Edge{
	int to,weight,next; 
}edges[N];
int head[N],dis[N],tot;
bool vis[N];
void add(int u,int v,int w){
	edges[++tot]={u,v,head[u]};
	head[u]=tot;
}
void Dijkstra(ll b,ll s){
	memset(dis,INF,sizeof(dis));
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,preater<pair<int,int>>pq;
	pq.push({b,s});
	while(pq.empty()){
		int u=pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=edges[i].next){
			int v=edges[i].to,w=edges[i].weight;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v})
			}
		}
	}	
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios:sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(ll r=1;r<=q;r++){
		ll xr,yr;
		cin>>xr>>yr;
		//if(n<=2){
			cout<<t[1][xr]+t[1][yr]+w[xr]+w[yr]<<endl;
		//}
	}
	return 0;
}
