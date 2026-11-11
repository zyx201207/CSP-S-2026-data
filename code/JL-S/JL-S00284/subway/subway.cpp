#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
const long long inf=0x3f3f3f3f3f3f3f3fll;
int c,n,m,d,q;
int w[M];
int k[N];
vector<pair<int,int> >F[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x,y;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			F[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int siz=F[i].size();
		for(int j=1;j<siz;j++){
			for(int k=0;k<j;k++){
				pair<int,int> p=F[i][j],q=F[i][k];
				int u=p.first,v=q.first;
				long long w=p.second+q.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for(int i=0;i<F[x].size();i++){
			for(int j=0;j<F[y].size();j++){
				ans=min(ans,F[x][i].second+dis[F[x][i].first][F[y][j].first]+F[y][j].second);
			}
		}
		ans=w[x]+ans+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}