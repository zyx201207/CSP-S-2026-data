#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
const int M=2e6;
int n,m;
int d,q;
int id;
int cnt;
int vis[N];
int dis[N];
int ww[N];
vector<pair<int,int> > a[505];
vector<int> num[505];
vector<pair<int,int> > g[M];
void dij(int s,int t){
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({-dis[s],s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(v==t){
//				cout<<u<<' '<<v<<' '<<w<<'\n';
			}
//			cout<<w<<"--------------";
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
			}
			q.push({-dis[v],v});
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<dis[i]<<' ';
//	}
	cout<<dis[t]+ww[s]+ww[t]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
		g[i].push_back({i+m,ww[i]});
		g[i+m].push_back({i,ww[i]});
	}
	cnt=2*m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			a[i].push_back({x,t});
			num[i].push_back(++cnt);
			g[num[i][j-1]].push_back({x,t});
			g[x].push_back({num[i][j-1],t});
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(j==l){
					continue;
				}
				g[num[i][j-1]].push_back({num[i][l-1],0});
				g[num[i][l-1]].push_back({num[i][j-1],0});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		dij(s,t);
	}
	return 0;
}