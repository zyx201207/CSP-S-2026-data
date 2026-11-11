#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000010];
int dp[2000010];
int f[2000010];
int s(int xx){
	for(int i=1;i<=n;i++){
		dp[i]=1e9;
		f[i]=0;
	}
	int ans=0;
	dp[xx]=0;
	f[xx]=1;
	for(int i=xx+1;i<=n;i++){
		int mi=1e9;
		int cnt=0;
		for(int j=xx+1;j<i;j++){
			if(x[i]-x[j]<=d){
				if(dp[j]==mi){
					cnt+=f[j];
				}
				if(dp[j]<mi){
					mi=dp[j];
					cnt=f[j];
				}
			}
		}
		dp[i]=mi+1;
		f[i]=cnt;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==2){
			ans++;
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=s(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}