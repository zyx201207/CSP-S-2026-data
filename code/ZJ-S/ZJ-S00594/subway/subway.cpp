#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,Q,head[N],nx[N<<1],to[N<<1],val[N<<1],cnt,a[N],t[N],dist[N],vis[N];
struct node{
	int dis,id;
	bool operator<(const node &x) const{
		return x.dis<dis;
	}
};

priority_queue<node> q;
void addedge(int u,int v,int w){
	nx[++cnt]=head[u];
	to[cnt]=v;
	val[cnt]=w;
	head[u]=cnt;
}
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	q.push((node){0,s});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nx[i]){
			int v=to[i],w=val[i];
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				if(!vis[v]) q.push((node){dist[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		addedge(i,i+m,x);
		addedge(i+m,i,x);
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j]>>t[j];
			for(int k=j-1;k>=1;k--){
				addedge(m+a[j],m+a[k],t[j]+t[k]);
				addedge(m+a[k],m+a[j],t[j]+t[k]);
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dist[y]<<endl;
	}
	return 0;
}