#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int arr[500005];
vector<pair<int,int> >g[1000005];
int dis[1000005],vis[1000005];
priority_queue<pair<int,int> >qu;
void dij(int x){
	memset(dis,0x3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	qu.push({0,x});
	dis[x]=0;
	while(!qu.empty()){
		int u=qu.top().second;
		qu.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					qu.push({-dis[v],v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		int k,lst=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({x+(j*m),y});
			g[x+(j*m)].push_back({x,y});
			if(j!=1){
				g[x+(j*m)].push_back({lst,0});
				g[lst].push_back({x+(j*m),0});
			}
			lst=x+(j*m);
		} 
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+arr[x]+arr[y]<<'\n';
	}
	return 0;
}
