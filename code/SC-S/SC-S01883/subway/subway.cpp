#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dis[1010][510],ans[1010][1010],a[20010];
bool vis[1010];
struct node{
	int xv,yv;
	ll w;
};
priority_queue<node> q;
bool operator<(node x,node y){
	return x.w>y.w;
}
vector<node> g[1010][510];
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	dis[s][0]=0;
	q.push({s,0,0});
	while(!q.empty()){
		node now=q.top();
		q.pop();
		int xv=now.xv,yv=now.yv;
		for(auto c:g[xv][yv]){
			int nx=c.xv,ny=c.yv;
			ll l=c.w;
			if(dis[xv][yv]+l<dis[nx][ny]){
				dis[nx][ny]=dis[xv][yv]+l;
				q.push({nx,ny,dis[nx][ny]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q67;
	cin>>c>>n>>m>>d>>q67;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int k,v,lstv;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll w;
			cin>>v>>w;
			g[v][0].push_back({v,i,w});
			g[v][i].push_back({v,0,w});
			if(j!=1){
				g[lstv][i].push_back({v,i,0});
				g[v][i].push_back({lstv,i,0});
			}
			lstv=v;
		}
	}
	for(int i=1;i<=m;i++){
		dij(i);
		for(int j=1;j<=m;j++)
			ans[i][j]=dis[j][0];
	}
	while(q67--){
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+a[x]+a[y]<<'\n';
	}
}