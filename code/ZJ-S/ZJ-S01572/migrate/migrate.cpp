#include<bits/stdc++.h>
using namespace std;
int c,t,n;
typedef long long ll;
ll d,ans;
ll x[2000005];
ll dp[5005][3];
void solve(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int t=0;t<3;t++) dp[i][t]=-2;
		}
		dp[i][0]=0;
		for(int t=i;t<=n;t++){
			for(int j=0;j<3;j++){
				ll sum=dp[t][j];
				if(sum==-2) continue;
				for(int z=i+1;z<=i+d && z<=n;z++){
					if(dp[z][0]>=sum+1){
						dp[z][2]=dp[z][1];
						dp[z][1]=dp[z][0];
						dp[z][0]=sum+1;
					}
					else if(dp[z][1]>=sum+1){
						dp[z][2]=dp[z][1];
						dp[z][1]=sum+1;
					}
					else dp[z][2]=min(dp[z][2],sum+1);
					for(int k=0;k<3;k++){
						if(dp[z][k]==-2){
							dp[z][k]=sum+1;
							break;
						}
					}
				}
			}
		}
		cout<<i<<'&';
		for(int t=i;t<=n;t++){
			if(dp[t][0]==dp[t][1] && dp[t][1]!=dp[t][2] && dp[t][1]!=-2) ans++;
			cout<<t<<' '<<dp[t][0]<<' '<<dp[t][1]<<' '<<dp[t][2]<<endl;
		}
	}
	printf("%lld\n",ans);
	return ;
}
void solveB(){
	ll a=2e18,b=-2e18;
	for(ll i=1;i<=n;i++){
		if(x[i]-x[1]<=d && x[n]-x[i]<=d){
			a=min(a,i);
			b=max(b,i);
		}
	}
//	cout<<a<<' '<<b<<' ';
	printf("%lld\n",(a-1)*(n-b)*(b-a+1));
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(c==13 || c==14)solveB();
		else if(c<=10) solve();
		else solveB();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
