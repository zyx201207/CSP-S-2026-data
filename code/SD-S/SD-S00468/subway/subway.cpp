#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=505,inf=1e18;
int c,n,m,d,q;
int w[M];
vector<pair<int,int> >v[M],e[N];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)	dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int x=0;x<(int)v[i].size();x++){
			for(int y=x+1;y<(int)v[i].size();y++){
				int a=v[i][x].first,b=v[i][y].first,tim=v[i][x].second+v[i][y].second;
				e[a].push_back({b,tim});
				dis[a][b]=min(dis[a][b],tim);
				dis[b][a]=min(dis[b][a],tim);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(pair<int,int>i:v[x]){
			for(pair<int,int>j:v[y]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
