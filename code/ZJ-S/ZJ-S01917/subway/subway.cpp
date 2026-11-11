#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500005],k[500005],x,y,dis[500505],u,v,w;
vector<pair<int,int> > e[500505];
bool vis[500505];
long long dijkstra(long long s,long long t){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qu;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	qu.push(make_pair(0,s));
	while(qu.size()){
		u=qu.top().second;
		qu.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			v=e[u][i].first;w=e[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				qu.push(make_pair(dis[v],v));
			}
		}
	}
	return dis[t];
}
long long bfs(long long s,long long t){
	queue<int> qu;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	qu.push(s);
	while(qu.size()){
		u=qu.front();
		qu.pop();
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			v=e[u][i].first;
			if(vis[v])continue;
			dis[v]=dis[u]+1;
			if(v==t)return dis[v]*e[u][i].second;
			qu.push(v);
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		if(k[i]==1){
			cin>>x>>y;
			continue;
		}
		if(k[i]==2){
			cin>>x>>y>>u>>v;
			e[x].push_back(make_pair(y,y+v));
			e[y].push_back(make_pair(x,y+v));
			continue;
		}
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			e[x].push_back(make_pair(n+i,y));
			e[n+i].push_back(make_pair(x,y));
		}
	}
	if(12<=c&&c<=19){
		while(q--){
			cin>>x>>y;
			cout<<a[x]+a[y]+bfs(x,y)<<'\n';
		}
		return 0;
	}
//	if(c<=8){
		while(q--){
			cin>>x>>y;
			cout<<a[x]+a[y]+dijkstra(x,y)<<'\n';
		}
//	}
	return 0;
}
