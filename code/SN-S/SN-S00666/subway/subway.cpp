#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,pair<int,int> > pii;
const int N=2e4+5;
int c,n,m,d,q,w[N],dis[N][25];
int a[505][505],t[505][505];
vector<int> id[N];
int k[N];
struct node{
	int idu,idv,to,dis;
};
vector<node> adj[N];
void solve(int x,int y){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=23;j++){
			dis[i][j]=0x3f3f3f3f;
		}
	}
	for(auto iid:id[x]){
		dis[x][iid]=0;
		q.push({0,{x,iid}});
	}
	while(!q.empty()){
		int u=q.top().second.first,iid=q.top().second.second;
		q.pop();
		for(auto v:adj[u]){
			int w=v.dis;
			if(dis[v.to][v.idv]>dis[u][iid]+w){
				dis[v.to][v.idv]=dis[u][iid]+w;
				q.push({dis[v.to][v.idv],{v.to,v.idv}});
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(auto iid:id[y]){
		ans=min(ans,dis[y][iid]+w[x]+w[y]);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			id[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			for(auto u:id[a[i][j]]){
				for(auto v:id[a[i][j+1]]){
					adj[a[i][j]].push_back({u,v,a[i][j+1],t[u][j+1]+t[v][j+1]});
					adj[a[i][j+1]].push_back({v,u,a[i][j],t[u][j+1]+t[v][j+1]});
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}


