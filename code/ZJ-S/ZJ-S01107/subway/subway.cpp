#include <bits/stdc++.h>
using namespace std;
#define int long long
int v[500010],k[510],a[500010],b[500010],dis[500010],vis[500010];
int c,n,m,d,qq,i,x,y,j,l;
vector<pair<int,int> > g[500010];
queue<int> q;
void dijkstra(int x){
	int i,sx,sb,fx;
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push(x);dis[x]=0;
	while(!q.empty()){
		fx=q.front();q.pop();
		if(vis[fx]) continue;
		vis[fx]=1;
		for(i=0;i<g[fx].size();i++){
			sx=g[fx][i].first;
			sb=g[fx][i].second;
			if(dis[fx]+sb<dis[sx]){
				dis[sx]=dis[fx]+sb;
				q.push(sx);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(i=1;i<=m;i++){
		cin>>v[i];
	}
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++){
			cin>>a[j]>>b[j];
		}
		for(j=1;j<k[i];j++){
			for(l=j+1;l<=k[i];l++){
				g[a[j]].push_back(make_pair(a[l],b[j]+b[l]));
				g[a[l]].push_back(make_pair(a[j],b[j]+b[l]));
			}
		}
	}
	while(qq--){
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]+v[x]+v[y]<<"\n";
	}
}

