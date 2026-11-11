#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010];
int k[500010];
int a;
int t;
int f[510][510];
vector<pair<int,int> >v[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a,&t);
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<v[i].size();x++){
			for(int y=0;y<v[i].size();y++){
				f[v[i][x].first][v[i][y].first]=min(f[v[i][x].first][v[i][y].first],v[i][x].second+v[i][y].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int xx,yy;
		scanf("%lld%lld",&xx,&yy);
		int ans=1e18;
		for(int x=0;x<v[xx].size();x++){
			for(int y=0;y<v[yy].size();y++){
				ans=min(ans,f[v[xx][x].first][v[yy][y].first]+v[xx][x].second+v[yy][y].second);
			}
		}
		printf("%lld\n",ans+w[xx]+w[yy]);
	}
	return 0;
}