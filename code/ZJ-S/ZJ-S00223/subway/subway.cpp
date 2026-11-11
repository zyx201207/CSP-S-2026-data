#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+1;
int c,n,m,s;
int w[N],pos[N*501];
vector<int> a[501],t[501];
struct edge{int v;ll w;};
vector<edge> g[N*501];
struct node{ll val;int id;};
bool operator<(node x,node y){return x.val>y.val;}
priority_queue<node> q;
ll dis[N*501];
bool vis[N*501];
void dijk(){
	for(int i = 1;i<=m*n;i++) dis[i]=4e18;
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]==1) continue;
		vis[x]=1;
		for(edge e:g[x]){
			int y=e.v,w=e.w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push({dis[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int lj,qu;
	cin>>c>>n>>m>>lj>>qu;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa),t[i].push_back(tt);
			pos[i*m+aa]=j;
		}
		for(int j = 0;j<a[i].size()-1;j++){
			int u=i*m+a[i][j],v=i*m+a[i][j+1];
			g[u].push_back({v,0});
			g[v].push_back({u,0});
		}
		for(int k = 1;k<=m;k++){
			for(int i = 1;i<=n;i++){
				if(pos[i*m+k]==0) continue;
				for(int j = 1;j<=n;j++){
					if(i==j) continue;
					if(pos[j*m+k]==0) continue;
					int u=pos[i*m+k]-1,v=pos[j*m+k]-1;
					ll w=t[i][u]+t[j][v];
					g[u].push_back({v,w});
					g[v].push_back({u,w});
				}
			}
		}
	}
	while(qu--){
		int is,ed;
		cin>>is>>ed;
		ll res=9e18;
		for(int i = 1;i<=n;i++){
			s=i*m+is;
			dijk();
			ll mn=9e18;
			for(int j = 1;j<=n;j++) mn=min(mn,dis[j*m+ed]);
			res=min(res,mn);
		}
		cout<<res+w[is]+w[ed]<<"\n";
	}
	return 0;
}
