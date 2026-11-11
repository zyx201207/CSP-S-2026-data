#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=5e2+10;
int C,n,m,d,Q,k,ans=0;
int a[N],b[N];
int g2[M][M],disans[M][M]; 
struct Node{
	int v,w;
};
vector<Node> g[N];
int dis[M];
bool vis[M];
operator <(Node x,Node y){
	return x.w<y.w;
}


void dij(int x){
	priority_queue<Node> pq;
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pq.push({x,0});
	dis[x]=0;
	while(!pq.empty()){
		int u=pq.top().v;
		pq.pop();
		if(!vis[u]){
			vis[u]=1;
			for(int i=1;i<=m;i++){
				int v=i,w=g2[u][i];
				if(v==u) continue;
				if(dis[v]>dis[u]+w){
					vis[v]=0;
					dis[v]=dis[u]+w;
					pq.push({v,dis[v]});
				}
			}
		}
	}
	for(int i=1;i<=m;i++) disans[x][i]=dis[i];
}

signed main(){
//	freopen("subway4.in","r",stdin);
//	freopen("subway4.in","r",stdin);
//	freopen("subway7.in","r",stdin);BU YAO BAO LING AAAAAA
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>m>>n>>d>>Q;//m=bian,n=dian
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>b[i];
		for(int j=1,v,w;j<=b[i];j++){
			cin>>v>>w;
			g[v].push_back({i,w});
		}
	}
	memset(g2,63,sizeof(g2));
	for(int i=1;i<=n;i++){
		for(auto x1:g[i]){
			for(auto x2:g[i]){
				g2[x1.v][x2.v]=min(g2[x1.v][x2.v],x1.w+x2.w);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<g2[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=m;i++){
		dij(i);
//		for(int j=1;j<=m;j++){
//			cout<<disans[i][j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1,x,y;i<=Q;i++){
		cin>>x>>y;
		int ans=1e17;
		for(auto x1:g[x]){
			for(auto x2:g[y]){
				ans=min(ans,disans[x1.v][x2.v]+x1.w+x2.w);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	
	return 0;
}
