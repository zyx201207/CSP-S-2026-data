#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+10;
int c,n,m,d,q,k[N],T;
int V[N<<1],nxt[N<<1],h[N],num,x[N],y[N];
int dis[N];
ll w[N],ans[N];
ll W[N<<1],dist[N];
bool vis[N];
struct node{
	int u;
	ll d;
	friend bool operator < (const node &x,const node &y){
		return x.d>y.d;
	}	
};
void add(int u,int v,ll w){
	V[++num]=v;
	nxt[num]=h[u];
	h[u]=num;
	W[num]=w;
}
void Dijkstra(int s){
	for(int i=1;i<=n+m;i++)vis[i]=false,dist[i]=1e18;
	dist[s]=0;
	priority_queue<node>q;
	q.push(node{s,0});
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int e=h[u];e;e=nxt[e]){
			if(dist[V[e]]>dist[u]+W[e]){
				dist[V[e]]=dist[u]+W[e];
				q.push(node{V[e],dist[V[e]]});
			}
		}
	}
}
void SPFA(int s){
	for(int i=1;i<=n+m;i++)vis[i]=false,dist[i]=1e18;
	dist[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=false;
		for(int e=h[u];e;e=nxt[e]){
			if(dist[V[e]]>dist[u]+W[e]){
				dist[V[e]]=dist[u]+W[e];
				if(!vis[V[e]])q.push(V[e]),vis[V[e]]=true;
			}
		}
	}
}
void bfs(int s){
	for(int i=1;i<=n+m;i++)dis[i]=-1;
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int e=h[u];e;e=nxt[e]){
			if(dis[V[e]]!=-1)continue;
			dis[V[e]]=dis[u]+1;
			q.push(V[e]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			T=t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i],ans[i]=1e18;
	if(c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			bfs(m+i);
			for(int j=1;j<=q;j++)ans[j]=min(ans[j],1ll*(dis[x[j]]+dis[y[j]])*T);
		}
	}
	else if(c>=22){
		for(int i=1;i<=n;i++){
			SPFA(m+i);
			for(int j=1;j<=q;j++)ans[j]=min(ans[j],dist[x[j]]+dist[y[j]]);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			Dijkstra(m+i);
			for(int j=1;j<=q;j++)ans[j]=min(ans[j],dist[x[j]]+dist[y[j]]);
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]+w[x[i]]+w[y[i]]<<'\n';
//	cerr<<(double)clock()/CLOCKS_PER_SEC<<'\n';
	return 0;
}