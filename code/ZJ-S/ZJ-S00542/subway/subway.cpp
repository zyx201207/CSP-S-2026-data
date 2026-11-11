#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int maxm=5e5+5;
const int maxn=505;
const int inf=1e18;
int c,n,m,d,q,w[maxm],k[maxm];
int dis[maxn][maxn];
vector<pii> sub[maxm];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			sub[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<sub[i].size();x++){
			for(int y=0;y<sub[i].size();y++){
				if(x==y)continue;
				int u=sub[i][x].first,v=sub[i][y].first;
				int dist=sub[i][x].second+sub[i][y].second;
				dis[u][v]=min(dis[u][v],dist);
				dis[v][u]=min(dis[v][u],dist);
			}
		}
	}
	for(int h=1;h<=n;h++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v,ans=inf;
		cin>>u>>v;
		for(int x=0;x<sub[u].size();x++){
			for(int y=0;y<sub[v].size();y++){
				int f=sub[u][x].first,g=sub[v][y].first;
				int dist=sub[u][x].second+sub[v][y].second;
				ans=min(ans,dis[f][g]+dist);
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}