#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 505
#define M 500005
int n,m,Q;
int w[M];
vector <int> g[M],gv[M];
int v[N][N];
struct node{
	int id,dis;
	bool operator < (const node &x) const {return dis>x.dis;}
};
priority_queue <node> q;
int vis[N],dis[N][N];
void dijkstra(int s){
	for (int i=1;i<=n;i++) dis[s][i]=4e18,vis[i]=0;
	dis[s][s]=0;
	q.push(node{s,0});
	while (q.size()){
		int x=q.top().id;
		q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int t=1;t<=n;t++){
			if (vis[t]) continue;
			if (dis[s][x]+v[x][t]<dis[s][t]){
				dis[s][t]=dis[s][x]+v[x][t];
				q.push(node{t,dis[s][t]});
			}
		}
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>n>>m>>Q>>Q; 
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		int t,x,y;
		cin>>t;
		for (int j=1;j<=t;j++){
			cin>>x>>y;
			g[x].push_back(i);
			gv[x].push_back(y);
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) v[i][j]=4e18;
	for (int i=1;i<=n;i++) v[i][i]=0;
	for (int i=1;i<=m;i++){
		for (int j=0;j<g[i].size();j++){
			for (int k=0;k<g[i].size();k++){
				int x=g[i][j],y=g[i][k];
				v[x][y]=min(v[x][y],gv[i][j]+gv[i][k]);
			}
		}
	}
	for (int i=1;i<=n;i++) dijkstra(i);
	while (Q--){
		int x,y,ans=4e18;
		cin>>x>>y;
		for (int i=0;i<g[x].size();i++){
			for (int j=0;j<g[y].size();j++){
				ans=min(ans,gv[x][i]+gv[y][j]+dis[g[x][i]][g[y][j]]);
			}
		}
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}
