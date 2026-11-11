#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5e5+9;
ll c,n,m,d,q;
ll w[M];
ll v[505][5000];
struct Edge{
	ll to,nxt,id;
}e[M];
ll nE,hd[M],in[M];
ll dis[M],vis[M];
void add(ll u,ll v,ll id){
	e[++nE]=(Edge){v,hd[u],id};
	//cout<<u<<" "<<v<<endl;
	hd[u]=nE;
}
struct Node{
	ll u,c,id;
	bool operator<(const Node&a)const{
		return a.c>c;
	}
};
ll tmp;
ll dijkstra(ll S,ll T){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	q.push((Node){S,0,0});
	dis[S]=0;

	//cout<<"1"<<endl;
	while(!q.empty()){
		Node nw=q.top(); q.pop();
		
		if(vis[nw.u]>=in[nw.u]) continue;
		vis[nw.u]++;
		//cout<<nw.u<<endl;
		for(ll i=hd[nw.u];i;i=e[i].nxt){
			//cout<<hd[nw.u]<<endl;
			ll id=e[i].id,to=e[i].to;
			ll w=0;
			if(nw.id!=id) w=v[id][nw.u]+v[nw.id][nw.u];
			if(dis[to]>dis[nw.u]+w){
				dis[to]=dis[nw.u]+w;
				//cout<<to<<" "<<nw.u<<" "<<dis[to]<<endl;
				q.push((Node){to,dis[to],id});
				if(to==T) tmp=id;
			}
		}
	}
	return dis[T];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		ll lst,first;
		ll h[k+1];
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			h[j]=a;
			v[i][a]=t;
			
			in[a]++;
			if(j==1) first=a;
			if(j!=1){
				for(ll k=1;k<j;k++){
					add(a,h[k],i);
					add(h[k],a,i);
				}
			}
			lst=a;
		}
	}
	while(q--){
		ll u,to;
		cin>>u>>to;
		ll ans=dijkstra(u,to);
		ans+=w[u]+w[to]+v[tmp][to];
		//for(ll i=1;i<=m;i++) cout<<dis[i]<<" ";
		//cout<<endl; 
		cout<<ans<<endl;
	}
	return 0;
}
