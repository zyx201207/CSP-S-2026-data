#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long c,n,m,d,q,w[N],k[N],a[1010][1010],t[1010][1010],x[N],y[N],dp[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=1e9;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			dp[a[i][j]][a[i][j-1]]=t[i][j];
			dp[a[i][j-1]][a[i][j]]=t[i][j-1];
		}
	}
	for(int z=1;z<=m;z++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][z]+dp[z][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%lld",dp[x[i]][y[i]]+w[x[i]]+w[y[i]]);
		puts("");
	}
    return 0;
}
