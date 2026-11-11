#include <bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int c,t;
long long n,d,ans;
long long a[N],vis[N],dp[N],l,r;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			dp[i]=1e18;
		}
		dp[1]=0;
		for (int i=2;i<=n;i++){
			for (int j=1;j<i;j++){
				if (a[i]-a[j]<=d){
					dp[i]=min(dp[j]+1,dp[i]);
				}
			}
		}
		for (int i=2;i<=n;i++){
			if (dp[i]-dp[i-1]<d && i!=2 && i!=n){
				for (int j=i-2;j>=1;j--){
					if (a[i]-a[j]<=d){
						l=j;
					}
				}
				for (int j=i+1;j<=n;j++){
					if (a[j]-a[i-1]<=d){
						r=j;
					}
				}
				ans+=(i-1-l)*(r-i);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
