#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[500050],dp[5050][5050],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=3) cout<<0<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[j-d]-a[j])<=d && abs(a[j]-a[i])>d) dp[i][j]=dp[i][j-d]+1;
				else if(abs(a[j]-a[i])<=d) dp[i][j]=1;
				else if(abs(a[j-1]-a[j])>d && abs(a[j]-a[i])>d) dp[i][j]=-LLONG_MAX;
				dp[j][i]=dp[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int sum=0;
				for(int k=1;k<=n;k++){
					if(i!=k && j!=k && i!=j && dp[i][j]!=-LLONG_MAX && dp[i][k]!=-LLONG_MAX && dp[k][j]!=-LLONG_MAX){
						if(dp[i][j]==dp[i][k]+dp[k][j]) sum++;
					}
				}
				if(sum==2) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
