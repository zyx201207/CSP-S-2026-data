#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q;
long long w[N];
vector<pair<int,long long> >pos[N];
long long dis[M][M];
void solve(){
	int u,v;
	long long ans=1e18;
	cin>>u>>v;
	for(int i=0;i<pos[u].size();i++){
		for(int j=0;j<pos[v].size();j++){
			//cout<<pos[u][i].second<<' '<<pos[v][j].second<<' '<<dis[pos[u][i].first][pos[v][i].first]<<' ';
			ans=min(ans,dis[pos[u][i].first][pos[v][j].first]+pos[u][i].second+pos[v][j].second);
		}
	}
	ans+=w[u]+w[v];
	//cout<<w[u]<<' '<<w[v];
	printf("%lld\n",ans);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
		//cout<<w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		dis[i][i]=0;
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			pos[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		int p=pos[i].size();
		for(int j=0;j<p;j++){
			for(int k=j+1;k<p;k++){
				long long val=pos[i][j].second+pos[i][k].second;
				int u=pos[i][j].first,v=pos[i][k].first;
				dis[u][v]=dis[v][u]=val;
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
		solve();
	}
}
