#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int INF=0x3f3f3f3f;
vector<pair<int,int>> g[MAXN];
int dis[MAXN];
bool vis[MAXN];
int w[MAXN];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void dijikstra(int s,int y){
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto e=pq.top();
		pq.pop();
		int u=e.second;
		if(vis[u]){
			continue;
		}
		for(auto edge:g[u]){
			int v=edge.first;
			int t1=edge.second;
			if(dis[v]>dis[u]+t1){
				dis[v]=dis[u]+t1;
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijikstra(x,y);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	
	return 0;
}/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
