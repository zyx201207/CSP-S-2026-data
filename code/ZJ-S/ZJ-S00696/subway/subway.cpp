#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],dist[505][505];
vector<pair<int,long long> >in[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		while(k--){
			long long a,t;
			scanf("%lld%lld",&a,&t);
			in[a].push_back({i,t});
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;++i) dist[i][i]=0;
	for(int i=1;i<=m;++i){
		for(int j=0;j<in[i].size();++j){
			long long u=in[i][j].first,disj=in[i][j].second;
			for(int k=j+1;k<in[i].size();++k){
				long long v=in[i][k].first,disk=in[i][k].second;
				dist[u][v]=dist[v][u]=min(dist[u][v],disj+disk);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=2e18;
		for(int i=0;i<in[x].size();++i){
			long long u=in[x][i].first,disx=in[x][i].second;
			for(int j=0;j<in[y].size();++j){
				long long v=in[y][j].first,disy=in[y][j].second;
				ans=min(ans,dist[u][v]+disx+disy);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
