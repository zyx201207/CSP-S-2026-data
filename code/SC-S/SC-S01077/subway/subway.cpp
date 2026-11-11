#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const long long inf=1e18;
int c,n,m,d,q;
long long w[maxn],ans[maxn];
vector<pair<int,long long>> g[maxn];

struct query{
	int started,ended,id;
}que[maxn];
bool cmp(query x,query y){
	return x.started<y.started;
}

int vis[maxn];
long long dis[maxn];
void dijkstra(int s){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	for(int i=1;i<=m;i++){
		vis[i]=0;dis[i]=inf;
	}
	dis[s]=0;
	pq.push({0,s});
	while(pq.size()){
		auto e=pq.top();pq.pop();
		int u=e.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto edge:g[u]){
			int v=edge.first;long long w=edge.second;
			if(!vis[v]){
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					pq.push({dis[v],v});
				}
			}
		}
	}
}

int k,sta[maxn];
long long t[maxn];
void make_edge(){
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			int u=sta[i],v=sta[j];
			g[u].push_back({v,t[i]+t[j]});
			g[v].push_back({u,t[i]+t[j]});
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sta[j]>>t[j];
		}
		make_edge();
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(x>y) swap(x,y);
		que[i]={x,y,i};
	}
	int last=0;
	sort(que+1,que+q+1,cmp);
	for(int i=1;i<=q;i++){
		int x=que[i].started,y=que[i].ended;
		if(x!=last) dijkstra(x);
		ans[que[i].id]=(dis[y]+w[x]+w[y]);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}