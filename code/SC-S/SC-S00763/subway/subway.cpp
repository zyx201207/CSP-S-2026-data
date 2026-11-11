#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[500005],t[500005],x[500005],y[500005],INF=2e9;
int dp[20010][20010];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m+1;i++)
		for(int j=1;j<=m+1;j++)
			dp[i][j]=INF;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[j],&t[j]);	
		}
		for(int j=1;j<=k[i];j++){
			for(int s=1;s<=k[i];s++){
				dp[a[j]][a[s]]=t[j]+t[s];
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);	
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int e=1;e<=m;e++){
				if(dp[j][e]!=INF&&dp[i][e]!=INF){
					dp[i][j]=min(dp[i][j],dp[j][e]+dp[i][e]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",dp[x[i]][y[i]]+w[x[i]]+w[y[i]]);
	return 0;
}