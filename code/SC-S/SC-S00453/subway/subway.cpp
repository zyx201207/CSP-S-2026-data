#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+1e5;
const int MAXN=505,MAXM=5e5+5,MAXEG=MAXM*20;
struct edge{int to,nxt,w;}eg[MAXEG];int head[MAXM*4],tot;
void addeg(int x,int y,int w){eg[++tot]={y,head[x],w};head[x]=tot;}
int dis[1005][1005];
int c,n,m,d,q;
int w[MAXM];
//地铁线 m+几号线   每个站展厅 几号站
struct node{
	int id,dist;
	bool operator < (const node &x)const{
		return dist>x.dist;
	}
};
bool vis[MAXM+MAXN];
void dij(int s){
	priority_queue<node> q;
	for(int i=1;i<=m+n;i++) vis[i]=0,dis[s][i]=inf;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().id,dd=q.top().dist;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=eg[i].nxt){
			int v=eg[i].to;
			if(eg[i].w+dis[s][u]<dis[s][v]){
				dis[s][v]=eg[i].w+dis[s][u];
				q.push({v,dis[s][v]});
			}
		}
	}
}
bool bj[MAXM];
int bdis[MAXM+MAXN];
int T;
void bfs(int s,int end){
	queue<int> q;
	for(int i=1;i<=n+m;i++) bdis[i]=inf,vis[i]=0;
	bdis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=eg[i].nxt){
			int v=eg[i].to;
			bdis[v]=min(bdis[v],bdis[u]+1);
			if(v==end){
				cout<<(T*bdis[v])+w[s]+w[end]<<"\n";
				return;
			}
			q.push(v);
		}
	}
}
void bfs2(int s,int end){
	queue<int> q;
	for(int i=1;i<=n+m;i++) bdis[i]=inf,vis[i]=0;
	bdis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=eg[i].nxt){
			int v=eg[i].to;
			bdis[v]=min(bdis[v],bdis[u]+eg[i].w);
			if(v==end){
				cout<<bdis[v]+w[s]+w[end]<<"\n";
				return;
			}
			q.push(v);
		}
	}
}
signed main(){
//	freopen("Bsub.txt","r",stdin);
//	freopen("comp.txt","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	bool tb=1;
	T=-1;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			if(T==-1) T=y;
			else if(T!=y) tb=0;
			addeg(x,m+i,y);
			addeg(m+i,x,y);
		}
	}
	if(n==2){
		while(q--){
			int x,y;cin>>x>>y;
			bfs2(x,y);
		}
		return 0;
	}
	if(tb){
		while(q--){
			int x,y;cin>>x>>y;
			bfs(x,y);
		}
		return 0;
	}
	while(q--){
		int x,y;cin>>x>>y;
		if(bj[x]) cout<<w[x]+w[y]+dis[x][y]<<"\n";
		else if(bj[y]) cout<<w[x]+w[y]+dis[y][x]<<"\n";
		else{
			dij(x);bj[x]=1;
			cout<<w[x]+w[y]+dis[x][y]<<"\n";
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 3 7 20 2
8 3 1 1 1 2 1
3 1 1 2 1 5 1
3 2 1 3 1 7 1
4 3 1 5 1 4 1 6 1
1 6
2 3

*/