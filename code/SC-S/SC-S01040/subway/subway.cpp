#include<bits/stdc++.h>
using namespace std;
int w[500010];
vector<pair<int,long long> > e[500010];
long long d[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d1,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d1,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			e[a].push_back({i,t});
		}
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=e[i].size();
		for(int k=0;k<sz;k++){
			for(int g=k+1;g<sz;g++){
				d[e[i][k].first][e[i][g].first]=min(d[e[i][k].first][e[i][g].first],e[i][k].second+e[i][g].second);
				d[e[i][g].first][e[i][k].first]=min(d[e[i][g].first][e[i][k].first],e[i][k].second+e[i][g].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				d[j][i]=min(d[j][i],d[j][k]+d[k][i]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		int sz1=e[x].size(),sz2=e[y].size();
		for(int i=0;i<sz1;i++){
			for(int j=0;j<sz2;j++){
				ans=min(ans,d[e[x][i].first][e[y][j].first]+e[x][i].second+e[y][j].second);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}