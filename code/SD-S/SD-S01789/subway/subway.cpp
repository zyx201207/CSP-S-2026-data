#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#define LL long long
using namespace std;
const int N=520;
const int M=5e5+100;
const LL INF=1e18;
int c,n,m,dd,q;
LL wt[M],d[N][N];
bool vis[N];
struct node{
	int v; LL dis;
};
vector<node> ss[M],e[N];
void build(int x){
	int k=ss[x].size();
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			int u=ss[x][i].v,v=ss[x][j].v;
			LL w=ss[x][i].dis+ss[x][j].dis;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
}
bool operator <(node x,node y){
	return x.dis>y.dis;
}
void dijkstra(int s){
	for(int i=1;i<=n;i++) vis[i]=0,d[s][i]=INF;
	priority_queue<node> q;
	d[s][s]=0; q.push({s,0});
	while(!q.empty()){
		int u=q.top().v; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		int k=e[u].size();
		for(int i=0;i<k;i++){
			int v=e[u][i].v; LL w=e[u][i].dis;
			if(d[s][u]+w<d[s][v]){
				d[s][v]=d[s][u]+w;
				q.push({v,d[s][v]});
			}
		}
	}
}
void solve(int x,int y){
	int kx=ss[x].size(),ky=ss[y].size();
	LL ans=INF;
	for(int i=0;i<kx;i++){
		for(int j=0;j<ky;j++){
			LL tx=ss[x][i].dis,ty=ss[y][j].dis;
			int u=ss[x][i].v,v=ss[y][j].v;
			ans=min(ans,d[u][v]+tx+ty);
		}
	}
	cout<<ans+wt[x]+wt[y]<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) cin>>wt[i];
	for(int i=1;i<=n;i++){
		int ki; cin>>ki;
		for(int j=1;j<=ki;j++){
			int u; LL w; cin>>u>>w;
			ss[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++) build(i);
	for(int i=1;i<=n;i++) dijkstra(i);
	for(int i=1;i<=q;i++){
		int x,y; cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
