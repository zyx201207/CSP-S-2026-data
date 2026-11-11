#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxm=5e5+5;
const int maxd=25;
long long tree[maxm][maxd],t[maxm][maxd],num[maxm];
long long dp[maxn][maxn];
long long ans,w[maxm];
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		long long a,tim,sum;
		scanf("%lld",&sum);
		for(int j=1;j<=sum;j++){
			scanf("%lld%lld",&a,&tim);
			num[a]++;
			tree[a][num[a]]=i;
			t[a][num[a]]=tim;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<num[i];j++){
			for(int k=j+1;k<=num[i];k++){
				dp[tree[i][k]][tree[i][j]]=min(dp[tree[i][k]][tree[i][j]],t[i][k]+t[i][j]);
				dp[tree[i][j]][tree[i][k]]=dp[tree[i][k]][tree[i][j]];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<i;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
				dp[k][j]=dp[j][k];
			}
		}
		for(int j=1;j<i;j++){
			for(int k=1;k<i;k++){
				dp[j][i]=min(dp[j][i],dp[j][k]+dp[k][i]);
				dp[i][j]=dp[j][i];
			}
		}
	}
	while(q--){
		ans=1e18;
		long long xr,yr;
		scanf("%lld%lld",&xr,&yr);
		for(int i=1;i<=num[xr];i++){
			for(int j=1;j<=num[yr];j++){
				ans=min(ans,dp[tree[xr][i]][tree[yr][j]]+t[xr][i]+t[yr][j]);
			}
		}
		printf("%lld\n",ans+w[xr]+w[yr]);
	}
	return 0;
}
//Oct31==Dec25?
