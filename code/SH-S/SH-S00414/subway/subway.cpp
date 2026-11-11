#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int C,n,m,d,q,W[N],ans[N][N];
struct node{
	int v,w;
};
vector<node> g[N];
int dis[N];
bool vis[N],flag[N];
bool operator <(const node &x,const node &y){
	return x.w>y.w;
}
void dijkstra(int s){
	priority_queue<node> q;
	q.push({s,0});
	for(int i=0;i<=m;i++) dis[i]=(int)1e18,vis[i]=false;
	dis[s]=0;
	while(q.size()){
		int x=q.top().v;q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(node kv:g[x]){
			int y=kv.v,w=kv.w;
			if(vis[y]) continue;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[s][i]=dis[i];
	}
	flag[s]=true;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> A(k+1),B(k+1);
		for(int j=1;j<=k;j++){
			cin>>A[j]>>B[j];
		}
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				g[A[u]].push_back({A[v],B[u]+B[v]});
				g[A[v]].push_back({A[u],B[u]+B[v]});
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(!flag[u]) dijkstra(u);
		cout<<W[u]+W[v]+ans[u][v]<<"\n";
	}
	return 0;
}
