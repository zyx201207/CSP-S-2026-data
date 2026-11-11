#include<bits/stdc++.h>
#define N 500005
#define M 505
#define ll long long
#define ls(v) ((v)<<1)
#define rs(v) (((v)<<1)|1)
#define pa pair<int,int>
#define fi first
#define se second
using namespace std;
const ll inf=1e18;
vector<pa >v[N];
ll d[M][M],w[N];
int c,n,m,ddd,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&ddd,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)d[i][j]=inf;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(pa{i,b});
		}
	}for(int i=1;i<=m;i++)for(auto vv:v[i])for(auto v2:v[i])d[vv.fi][v2.fi]=min(d[vv.fi][v2.fi],1LL*vv.se+v2.se);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(d[i][k]!=inf)for(int j=i+1;j<=n;j++)d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b){
			printf("0\n");
			continue;
		}ll ans=inf;
		for(auto vv:v[a])for(auto v2:v[b])ans=min(ans,d[vv.fi][v2.fi]+vv.se+v2.se);
		printf("%lld\n",ans+w[a]+w[b]);
	}
	return 0;
}