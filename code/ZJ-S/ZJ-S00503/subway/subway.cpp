#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005],c,n,m,d,q,cnt;
vector<pair<int,int> > G[1000005];
vector<int> line[505];
vector<pair<int,int> > Q[500005];
int dis[1000005];
int ans[100005];
bool vis[500005];
void dijkstra(int st){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	dis[st]=0;q.push({0,st});
	while(q.size()){
		int p=q.top().second,w=q.top().first;
		q.pop();
		if(w!=dis[p]) continue;
		for(auto v:G[p]){
			int to=v.first;
			if(dis[to]>dis[p]+v.second){
				dis[to]=dis[p]+v.second;
				q.push({dis[to],to});
			}
		}
	}
}
void bfs(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	deque<int> q;
	q.push_back(st);dis[st]=0;vis[st]=1;
	while(q.size()){
		int p=q.front();q.pop_front();vis[p]=1;
		for(auto v:G[p]){
			int to=v.first;
			if(vis[to]) continue;
			if(v.second>0){
				q.push_back(to);dis[to]=dis[p]+v.second;vis[to]=1;
			}else{
				q.push_front(to);dis[to]=dis[p];vis[to]=1;
			} 
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	cnt=m;
	if(c<16){
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			for(int j=1,a,t;j<=k;j++){
				cin>>a>>t;cnt++;
				G[a].push_back({cnt,t});
				G[cnt].push_back({a,t});
				line[i].push_back(cnt);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<line[i].size();j++){
				G[line[i][j-1]].push_back({line[i][j],0});
				G[line[i][j]].push_back({line[i][j-1],0});
			}
		}
	}
	if(c<9){
		while(q--){
			int st,ed;cin>>st>>ed;
			dijkstra(st);
			cout<<dis[ed]+w[st]+w[ed]<<"\n";
		}
	}else if(c>=9&&c<=11){
		for(int i=1;i<=q;i++){
			int st,ed;cin>>st>>ed;
			Q[st].push_back({ed,i});
		}
		for(int i=1;i<=m;i++){
			if(Q[i].size()==0) continue;
			dijkstra(i);
			for(auto j:Q[i]){
				ans[j.second]=w[i]+w[j.first]+dis[j.first];
			}
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	}else if(12<=c&&c<=15){
		while(q--){
			int st,ed;cin>>st>>ed;
			bfs(st);
			cout<<dis[ed]+w[st]+w[ed]<<"\n";
		}
	}
	return 0;
}
