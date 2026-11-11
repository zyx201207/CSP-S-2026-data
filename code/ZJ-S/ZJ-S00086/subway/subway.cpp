#include<bits/stdc++.h>
using namespace std;

const int MAXM=5e5+1000;
const int INF=1e9+100;

int w[MAXM];
vector<pair<int,int> > f[MAXM];
vector<pair<int,int> > G[MAXM];

bool vis[MAXM];
int dis[MAXM];
int Dijkstra(int s,int f){
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<int,vector<int>,greater<int>  > q;
	q.push(s);
	vis[s]=1;dis[s]=0;
	while(!q.empty()){
		int u=q.top();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].first,dd=G[u][i].second;
			if(vis[v]==1) continue;
			if(dis[u]+dd<dis[v]){
				dis[v]=dis[u]+dd;
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return dis[f];
}

int c,n,m,d,q,ans=INF;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			pair<int,int> xx;
			xx.first=-i;xx.second=t;
			f[a].push_back(xx);
		}
	}
	for(int i=1;i<=m;i++){
		if(f[i].size()>1){
			for(int j=0;j<f[i].size();j++){
				int u=f[i][j].first,d1=f[i][j].second;
				for(int k=j+1;k<f[i].size();k++){
					int v=f[i][k].first,d2=f[i][k].second;
					pair<int,int> xx;
					xx.first=-v;xx.second=d1+d2;
					G[-u].push_back(xx);
					xx.first=-u;
					G[-v].push_back(xx);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=INF;
		for(int i=0;i<f[x].size();i++){
			for(int j=i+1;j<f[y].size();j++){
				ans=min(ans,Dijkstra(-f[x][i].first,-f[y][i].second)+w[-f[x][i].first]+w[-f[y][i].second]+f[x][i].second+f[y][i].second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
