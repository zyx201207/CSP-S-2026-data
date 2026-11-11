#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=INT_MAX;\

vector<pair<int,int>> g[N];
int dist[N];
bool vis[N];

int d[N];
int n,k;

int pa[N];
int sz[N];

int find(int x){
	if(x!=pa[x]) pa[x]=find(pa[x]);
	return pa[x];
}

void merge(int a,int b){
	sz[0]=0;
	sz[a]=1;sz[b]=1;
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb){
		fa=find(fa);
		fb=find(fb);
	}
	sz[fa]+=fb;
}

bool dfs(int u,int p){
	int cnt=0;
	for(auto &e:g[u]){
		int v=e.first;
		if(v==p) continue;
		else {
			cnt++;
			merge(u,v);
			dfs(v,u);
		}
	}
	if(cnt==k) return true;
	else return false;
}

int dijkstra(int s,int t){
	for(int i=1;i<=n;i++){
		dist[i]=INF;
		vis[i]=false;
	}
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	while(!q.empty()){		
		int d=q.top().first;
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto &edge:g[u]){
			int v=edge.first;
			int w=edge.second;
			if(dist[v]>d+w){
				dist[v]=d+w;
				q.push({dist[v],v});
			}
		}
	}
	return dist[t];
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) d[i]=INF;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back({v,1});
		g[v].push_back({u,1});
	}
	for(int i=1;i<=n;i++){
		if(dfs(i,0)) break;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(dijkstra(i,j)!=INF) 
				d[i]=min(d[i],dijkstra(i,j));
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,d[i]);
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
