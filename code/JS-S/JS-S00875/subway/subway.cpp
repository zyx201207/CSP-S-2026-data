#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

const int N=505,M=500005;
const ll INF=90000000000000007ll;

int c,n,m,d,q;
ll w[M],f[N][N];
vector<pair<int,ll> > e[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int i,j,k,x,y;
	ll v;

	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);

	for(i=1;i<=m;i++)
		scanf("%lld",&w[i]);

	for(i=1;i<=n;i++){
		scanf("%d",&k);

		while(k--){
			scanf("%d%lld",&x,&v);
			e[x].push_back({i,v});
		}
	}

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=INF;

	for(i=1;i<=n;i++)
		f[i][i]=0;

	for(i=1;i<=m;i++)
		for(j=0;j<e[i].size();j++)
			for(k=j+1;k<e[i].size();k++){
				x=e[i][j].first,y=e[i][k].first,v=e[i][j].second+e[i][k].second;
				f[x][y]=min(f[x][y],v);
				f[y][x]=min(f[y][x],v);
			}

	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

	while(q--){
		scanf("%d%d",&x,&y);
		v=INF;

		for(i=0;i<e[x].size();i++)
			for(j=0;j<e[y].size();j++)
				v=min(v,e[x][i].second+f[e[x][i].first][e[y][j].first]+e[y][j].second);

		printf("%lld\n",v+w[x]+w[y]);
	}

	return 0;
}