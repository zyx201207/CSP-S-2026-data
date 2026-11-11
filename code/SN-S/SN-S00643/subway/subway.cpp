#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
struct node{
	int v;
	int w;
};
vector<node>ve[N];
int c,n,m,d,q;
int x,y;
int a[N];
int g[N];
int dis[N];
void dij(){
	priority_queue<pair<int,int> >q;
	int vis[N]={};
	
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	q.push({0,x});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int j=0;j<ve[u].size();j++){
			int v=ve[u][j].v;
			int w=ve[u][j].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		int u=m+i;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			ve[u].push_back({v,w});
			ve[v].push_back({u,w});
			
		}
	}
	while(q--){
		cin>>x>>y;
		dij();
		cout<<a[x]+a[y]+dis[y]<<endl;
	}
	return 0;
}

