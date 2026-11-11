#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500010];
int g[510][510];
long long dist[510][510];
vector<pair<long long,int> > v[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<=n;i++){
		for(long long j=0;j<=n;j++){
			if(i!=j){
				g[i][j]=1e18;
				dist[i][j]=1e18;	
			}
		}
	}
	
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long a;
			int t;
			scanf("%lld %d",&a,&t);
			v[a].push_back({i,t});
		}
	}
	
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<v[i].size();j++){
			for(long long o=j+1;o<v[i].size();o++){
				g[v[i][j].first][v[i][o].first]=min(g[v[i][j].first][v[i][o].first],v[i][j].second+v[i][o].second);
			}
		}
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(g[i][j]==1e18){
				g[i][j]=g[j][i];
				dist[i][j]=g[i][j];
				dist[j][i]=g[i][j];
			}
		}
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				dist[j][i]=dist[i][j];
			}
		}
	}
	
	for(long long i=1;i<=q;i++){
	
		long long ans=1e18;
		long long from,to;
		scanf("%lld %lld",&from,&to);
		for(long long j=0;j<v[from].size();j++){
			for(long long k=0;k<v[to].size();k++){
				ans=min(ans,dist[v[from][j].first][v[to][k].first]+v[from][j].second+v[to][k].second);
			}
		}
		ans+=w[from]+w[to];
		printf("%lld\n",ans);
	}
	return 0;
}