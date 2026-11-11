#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],dp[N][2];
void f(int x){
	for(int i=x+1;i<=n;i++){
		for(int j=i-1;j>=x;j--){
			if(a[i]-a[j]>d) break;
			int nw=dp[j][0]+1;
			if(dp[i][0]>nw){
				dp[i][0]=nw,dp[i][1]=dp[j][1];
			}
			else if(dp[i][0]==nw){
				dp[i][1]+=dp[j][1];
			}
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[j][0]=2e9,dp[j][1]=0;
			}
			dp[i][0]=0,dp[i][1]=1;
			f(i);
			for(int j=i;j<=n;j++){
				if(dp[j][1]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
