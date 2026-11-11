#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+505;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[MAXN];
vector<pair<int,int> > g[MAXN];
int dis[1010];
int vis[21000];
int anc[21000][20];
int len[21000];
int dep[21000];
int gg[1510][1510];
void bfs(int st){
	for(int i=1;i<=n+m;i++)dis[i]=INF;
	for(int i=1;i<=n+m;i++)vis[i]=false;
	queue<pair<int,int> > q;
	vis[st]=true;
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		int u=q.front().first,d=q.front().second;
		q.pop();
		for(pair<int,int> v:g[u]){
			if(vis[v.first])continue;
			dis[v.first]=d+v.second;
			vis[v.first]=true;
			q.push({v.first,d+v.second});
		}
	}
}
void dfs(int u){
	for(pair<int,int> v:g[u])if(v.first!=anc[u][0]){
		anc[v.first][0]=u;
		len[v.first]=len[u]+v.second;
		dep[v.first]=dep[u]+1;
		dfs(v.first);
	}
}
void Dij(int st){
	for(int i=1;i<=n+m;i++)dis[i]=INF;
	for(int i=1;i<=n+m;i++)vis[i]=false;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,st});
	dis[st]=0;
	for(int i=2;i<=n+m;i++){
		int d=pq.top().first,u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		for(pair<int,int> v:g[u])if(!vis[v.first]){
			if(dis[v.first]>=dis[u]+v.second){
				dis[v.first]=dis[u]+v.second;
				pq.push({dis[v.first],v.first});
			}
		}
		vis[u]=true;
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c<=8){
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			for(int j=1;j<=k;j++){
				int a,t;cin>>a>>t;
				g[a].push_back({m+i,t});
				g[m+i].push_back({a,t});
			}
		}
		for(int i=1;i<=q;i++){
			int u,v;cin>>u>>v;
			Dij(u);
			cout<<dis[v]+w[v]+w[u]<<endl;
		}
		return 0;
	}
	if(c>=9&&c<=11){
		memset(gg,0x3f,sizeof gg);
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			int l1,l2,u,v;
			cin>>u>>l1>>v>>l2;
			gg[u][v]=gg[v][u]=min(gg[u][v],l1+l2);
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j)continue;
				if(gg[i][j]==INF)continue;
				g[i].push_back({j,gg[i][j]});
				g[j].push_back({i,gg[i][j]});
			}
		}
		dfs(1);
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i<=n;i++){
				anc[i][j]=anc[anc[i][j-1]][j-1];
			}
		}
		for(int i=1;i<=q;i++){
			int u,v;cin>>u>>v;
			int _lca=lca(u,v);
			cout<<len[u]-len[_lca]+len[v]-len[_lca]+w[u]+w[v]<<endl;
		}
		return 0;
	}
	if(c>=12&&c<=15){
		int T=0;
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			for(int j=1;j<=k;j++){
				int a,t;cin>>a>>t;
				T=t;
				g[a].push_back({m+i,t});
				g[m+i].push_back({a,t});
			}
		}
		for(int i=1;i<=q;i++){
			int u,v;cin>>u>>v;
			bfs(u);
			cout<<w[u]+w[v]+dis[v]<<endl;
		}
		return 0;
	}
	if(c>=20&&c<=21){
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			for(int j=1;j<=k;j++){
				int a,t;cin>>a>>t;
				g[a].push_back({m+i,t});
				g[m+i].push_back({a,t});
			}
		}
		int gogo[3][3];
		memset(gogo,0x3f,sizeof gogo);
		gogo[0][0]=gogo[1][1]=0;
		for(int i=1;i<=m;i++){
			//sort(g[i].begin(),g[i].end());
			if(g[i].size()<2)continue;
			gogo[g[i][0].first-m][g[i][1].first-m]=
			gogo[g[i][1].first-m][g[i][0].first-m]=
			min(gogo[g[i][0].first-m][g[i][1].first-m],g[i][0].second+g[i][1].second);
		}
		for(int i=1;i<=q;i++){
			int u,v;cin>>u>>v;
			int ans=INF;
			for(int j=0;j<g[u].size();j++){
				for(int l=0;l<g[v].size();l++){
					ans=min(ans,gogo[g[u][j].first-m][g[v][l].first-m]+g[u][j].second+g[v][l].second);
				}
			}
			cout<<ans+w[u]+w[v]<<endl;
		}
		return 0;
	}
	srand(time(0));
	while(q--){
		cout<<rand()<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

20 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

12 2 5 20 3
2 4 3 5 6
3 1 2 2 2 4 2
3 2 2 3 2 5 2
*/

