#include<bits/stdc++.h>
using namespace std;
int t[500009];
long long dp[2009][2009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",t+i);
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			dp[a][m+i]=b;
			dp[m+i][a]=b;
		}
	}
	for(int i=1;i<=m+n;i++)dp[i][i]=0;
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		long long sum=(long long)t[a]+t[b]+dp[a][b];
		printf("%d\n",sum);
	}
	return 0;
}
