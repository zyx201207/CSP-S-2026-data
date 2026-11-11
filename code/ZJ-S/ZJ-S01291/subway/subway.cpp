#include<cstdio>
#include<vector>
#define int long long
#define MAXN 505
#define MAXM 500100
inline int min(int a,int b){return a<b?a:b;}
int c,n,m,d,Q;
int w[MAXM],k[MAXN];
int a[MAXN][1005],t[MAXN][1005];
int mapf[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=501;i++)for(int j=1;j<=1001;j++)mapf[i][j]=1000000000000000000ll;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)scanf("%lld%lld",&a[i][j],&t[i][j]);
		for(int j=1;j<=k[i];j++){
			for(int p=1;p<=k[i];p++){
				if(j==p)mapf[a[i][j]][a[i][p]]=0;
				else mapf[a[i][j]][a[i][p]]=min(mapf[a[i][j]][a[i][p]],t[i][j]+t[i][p]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			printf("%lld ",mapf[i][j]);
//		}putchar('\n');
//	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				mapf[i][k]=min(mapf[i][k],mapf[i][j]+mapf[j][k]);
			}
		}
	}
	while(Q--){
		int x,y,ans=0;
		scanf("%lld%lld",&x,&y);
		ans=w[x]+w[y]+mapf[x][y];
		printf("%lld\n",ans);
	}
	return 0;
}/*
ditiekou
w[v]
zhanting   m

zhantai*/