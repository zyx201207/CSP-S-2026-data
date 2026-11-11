#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,w[M],k[N];
vector<pair<int,int> >a[N],v[M];
long long f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1ll<<59;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		a[i].resize(k[i]+3);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j].first,&a[i][j].second);
			for(auto x:v[a[i][j].first])
				f[x.first][i]=f[i][x.first]=min(f[x.first][i],0ll+a[i][j].second+x.second);
			v[a[i][j].first].push_back({i,a[i][j].second});
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			printf("%lld ",f[i][j]);
//		printf("\n");
//	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=LLONG_MAX;
		for(auto i:v[x])
			for(auto j:v[y])
				ans=min(ans,f[i.first][j.first]+i.second+j.second+w[x]+w[y]);
		printf("%lld\n",ans);
	}
	return 0;
}
