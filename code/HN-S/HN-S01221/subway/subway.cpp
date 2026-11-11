#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=510,M=5e5+10;
int n,m,c,d,Q;
vector<pii> g[M],a[N];
int v[M],w[N][N],dis[N][N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii> > q;

void chkmin(int &x,int y){
	x=min(x,y);
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(w,0x3f,sizeof w);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		while(t--){
			int to,w;
			cin>>to>>w;
			a[i].push_back({to,w});
			g[to].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<g[i].size();x++)
			for(int y=x+1;y<g[i].size();y++){
				chkmin(w[g[i][x].first][g[i][y].first],g[i][x].second+g[i][y].second);
				chkmin(w[g[i][y].first][g[i][x].first],g[i][x].second+g[i][y].second);
			}
	}
	for(int st=1;st<=n;st++){
		memset(vis,0,sizeof vis);
		memset(dis[st],0x3f,sizeof dis[st]);
		while(!q.empty())q.pop();
		q.push({0,st});
		dis[st][st]=0;
		while(!q.empty()){
			int x=q.top().second;
			q.pop();
			if(vis[x])continue;
			vis[x]=1;
			for(int i=1;i<=n;i++)
				if(dis[st][i]>dis[st][x]+w[x][i]){
					dis[st][i]=dis[st][x]+w[x][i];
					q.push({dis[st][i],i});
				}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<g[x].size();i++)
			for(int j=0;j<g[y].size();j++){
				chkmin(ans,g[x][i].second+g[y][j].second+dis[g[x][i].first][g[y][j].first]);
			}
		cout<<ans+v[x]+v[y]<<'\n';
	}
	return 0;
}
