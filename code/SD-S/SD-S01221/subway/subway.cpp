#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550+10;
const int M=5e5+10;
int c,n,m,d,q1;
int w[M],dis[M<<1],k[N];
struct nn{
	int to,val;
};
vector<nn> g[M<<1];
priority_queue<nn> q;
bool operator<(nn x,nn y){
	return x.val>y.val;
}
int tot;
bool vis[M<<1];
void dij(int x){
	for(int i=1;i<=tot;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[x]=0;
	q.push({x,0});
	while(!q.empty()){
		nn f=q.top();
		q.pop();
		int u=f.to;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
		 	int v=g[u][i].to;
		 	if(dis[v]>dis[u]+g[u][i].val){
		 		dis[v]=dis[u]+g[u][i].val;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
  	freopen("subway.in","r",stdin);
  	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	tot=m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int lst=0;
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			tot++;
			g[x].push_back({tot,y});
			g[tot].push_back({x,y});
			if(lst){
				g[lst].push_back({tot,0});
				g[tot].push_back({lst,0});
			}
			lst=tot;
		}
	}
	while(q1--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<w[x]+w[y]+dis[y]<<'\n';
	}
	return 0;
}
