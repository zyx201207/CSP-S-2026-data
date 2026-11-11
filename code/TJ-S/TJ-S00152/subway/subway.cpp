#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1010];
long long dis[1010][1010];
bool vis[1010];
struct edge{
	int v,t;
};
vector<edge> g[1010];
void dfs(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=true;
		for(edge e:g[u]){
			int v=e.v,t=e.t;
			if(vis[v])continue;
			dis[s][v]=min(dis[s][v],dis[s][u]+1ll*t);
			q.push(v);
		}
	} 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[1010],t[1010];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int z=1;z<j;z++){
				g[a[j]].push_back({a[z],t[j]+t[z]});
				g[a[z]].push_back({a[j],t[j]+t[z]});
			}
		}
	}
	memset(dis,0x3f3f3f3f3f3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		memset(vis,false,sizeof(vis));
		dfs(i);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
    return 0;
}

