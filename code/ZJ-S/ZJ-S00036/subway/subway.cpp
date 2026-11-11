#include <bits/stdc++.h>
using namespace std;
const int maxm=5e5+10;
struct edge{
	int to,num;
};
int w[maxm],c,n,m,d,q,t[maxm][100],dis[maxm],vis[maxm],rec[101][maxm];
vector <edge> maps[maxm];
vector <int> past[maxm];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,lst,u,a;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>a;
			rec[i][j]=u;
			if(!past[u].empty())
			t[u][i]=a;
			if(j!=1){
				maps[u].push_back({0,lst});
				maps[lst].push_back({0,u});
			}
			lst=u;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		queue <edge> q;
		q.push({0,x});
		dis[x]=0;
		while(!q.empty()){
			edge now=q.front();
			q.pop();
			int u=now.to;
			if(vis[u])continue;
			vis[u]=1;
			for(auto nxt:maps[u]){
				int v=nxt.to;
				if(nxt.num!=now.num){
					dis[v]=min(dis[v],dis[u]+t[u][now.num]+t[v][nxt.num]);
				}
				else{
					dis[v]=min(dis[v],dis[u]);
				}
				q.push({nxt});
			}
		}
		cout<<w[x]+dis[y]+w[y]<<'\n';
	}
}