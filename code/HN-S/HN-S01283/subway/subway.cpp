#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;
int c,n,m,d,q1;
long long dis[1000010],vis[1000010];
long long Now;
struct node{
	int finish,value;
}nod[1000010];
vector<node> g[1000010];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dijkstra(int s){
	for(int i=1;i<=Now;i++){
		dis[i]=1e10;
	}
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int t=q.top().second;
		q.pop();
		if(vis[t]==1){
			continue;
		}
		vis[t]=1;
		for(int i=0;i<g[t].size();i++){
			int f=g[t][i].finish;
			int v=g[t][i].value;
			if(dis[f]>dis[t]+v){
				dis[f]=dis[t]+v;
				q.push(make_pair(dis[f],f));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	Now=m;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		Now++;
		g[i].push_back({Now,w});
		g[Now].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		Now++;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			g[Now].push_back({v+m,w});
			g[v+m].push_back({Now,w});
		}
	}
	for(int i=1;i<=q1;i++){
		int x,y;
		cin>>x>>y;
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dijkstra(x);
		cout<<dis[y]<<'\n';
	}
	return 0;
}
