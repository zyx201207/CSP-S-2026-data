#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int M=5e5+5;
const int N=505;
const int INF=1e18+5;
int w[M];
int dis[N][N];
vector< pair<int,int> > adj[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1,x,t;j<=k;j++){
			scanf("%lld%lld",&x,&t);
			adj[x].push_back({i,t});
		}
	}
	for(int i=1,len;i<=m;i++){
		len=adj[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				dis[adj[i][j].first][adj[i][k].first]=min(dis[adj[i][j].first][adj[i][k].first],adj[i][j].second+adj[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				dis[i][j]=0;continue;
			}
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	int x,y,ans;
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=INF;
		for(pair<int,int> i:adj[x]){
			for(pair<int,int> j:adj[y]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}