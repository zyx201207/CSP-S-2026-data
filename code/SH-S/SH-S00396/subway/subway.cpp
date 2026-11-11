#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int c,n,m,d,q;
int a[MAXN];
struct edge{
	int v,w;
};
vector<edge>G[MAXN];
int dis[MAXN];
queue<int>que;
void Dijkstra(int s){
	dis[s]=a[s];
	que.push(s);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(auto x:G[u]){
			int v=x.v,w=x.w;
			if(v==u)continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push(v);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			G[u].push_back({m+i,w});
			G[m+i].push_back({u,w});
		}
	}
	while(q--){
		memset(dis,0x3f,sizeof(dis));
		int x,y;
		cin>>x>>y;
		Dijkstra(x);
		cout<<dis[y]+a[y]<<endl;
	}
	return 0;
}
