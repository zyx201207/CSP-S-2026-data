#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
typedef pair<int,int>pii;
vector<int>g[MAXN];
int dis[MAXN];
bool vis[MAXN];
int INF=0x3f;
int maxx;
void dfs(){
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,1});
	while(!pq.empty()){
		auto e=pq.top();
		pq.pop();
		int d=e.first;
		int u=e.second;
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:g[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				maxx=min(dis[v],maxx);
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		maxx=INT_MAX;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(dis,0x3f,sizeof(dis));
		memset(vis,false,sizeof(vis));
		dis[1]=0;
		dfs();
		cout<<maxx<<"\n";
	}
	return 0;
}
