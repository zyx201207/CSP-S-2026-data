#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
const int N=509,M=5e5+7;
struct node{
	int id;
	long long len;
	friend bool operator<(node a,node b){
		return (a.len>b.len);
	}
};
struct edge{
	int u,v;
}e[N*N];
const long long INF=1e18+7;
long long trs[N][N],dis[N][N];
int vis[N][M],ent[M],ext[N];
int c,n,m,d,t,E=1;
vector<node> g[N];
vector<int> way[M];
priority_queue<node> q;
void rdi(){
	cin>>c>>n>>m>>d>>t;
	for(long long i=1;i<=m;i++) cin>>ent[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) trs[i][j]=INF;
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int dest,wei; cin>>dest>>wei;
			way[dest].push_back(i);
			vis[i][dest]=wei;
			for(int p=1;p<i;p++){
				if(vis[p][dest]){
					trs[i][p]=min(trs[i][p],
					(long long)(vis[i][dest]+vis[p][dest]));
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(trs[i][j]){
				g[i].push_back({j,trs[i][j]});
				g[j].push_back({i,trs[i][j]});
				e[E++]={i,j};
			}
		}
	}
	E--;
}
void Dij(int s){
	for(int i=1;i<=n;i++){
		ext[i]=0;
		dis[s][i]=INF;
	}
	q.push({s,0});
	dis[s][s]=0;
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(ext[u.id]) continue;
		else ext[u.id]=1;
		for(int i=0;i<g[u.id].size();i++){
			node v=g[u.id][i];
			if(u.len+v.len<dis[s][v.id]){
				dis[s][v.id]=u.len+v.len;
				q.push({v.id,u.len+v.len});
			}
		}
	}
}
void st(){
	for(int i=1;i<=n;i++) Dij(i);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	rdi();
	st();
	while(t--){
		int s,e; cin>>s>>e;
		long long ans=INF;
		for(int i=0;i<way[s].size();i++){
			int rti=way[s][i];
			for(int j=0;j<way[e].size();j++){
				int rtj=way[e][j];
				ans=min(ans,dis[rti][rtj]+vis[rti][s]+vis[rtj][e]);
			}
		}
		cout<<ans+ent[s]+ent[e]<<endl;
	}
	return 0;
}
