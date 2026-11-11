#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,inf=1e9;
int c,n,m,d,q,x,y,k[505],a[505][N],t[505][N],w[N];
struct node{
	int v,val;
};
vector<node>e[N];
int vis[505],dis[505],ans;

void dijkstra(int s){
	for(int i=0;i<=m;i++) {
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	vis[s]=1;
	for(int i=1;i<=m;i++){
		int u=0;
		for(int j=1;j<=m;j++){
			if(!vis[j]&&dis[j]<dis[u]) u=j;
		}
		vis[u]=1;
		for(auto k:e[u]){
			int tv=k.v,w=k.val;
			if(dis[tv]>dis[u]+w){
				dis[tv]=dis[u]+w;
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j/2]>>t[i][j/2];
		}
	}
//	cout<<"ok"<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			int u=a[i][j],v=a[i][j+1],w=t[i][j]+t[i][j+1];
//			cout<<"u="<<u<<" v="<<v<<'\n';
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
	
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];
		dijkstra(x);
		ans+=dis[y];
		cout<<ans<<'\n';
	}
	return 0;
}