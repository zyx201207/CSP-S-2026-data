#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,d,a[2000005],dp[5005][5005];
void once(void){
	memset(a,0,sizeof(a));
	memset(dp,0x3f,sizeof(dp));
	cin>>n>>d;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for (int i=1;i<n;i++)
		dp[i][i+1]=(int)(a[i+1]-a[i]<=d);
	for (int l=3;l<=n;l++){
		for (int i=1;i+l-1<=n;i++){
			int j=i+l-1,w=0;
			bool flag=false;
			for (int k=i+1;k<j;k++){
				if (dp[k-1][k]==0||dp[k][k+1]==0)
					flag=true;
				if (dp[i][k]+dp[k][j]<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
					w=1;
				}else if (dp[i][k]+dp[k][j]==dp[i][j])
					w++;
			}
			if (flag) continue;
			if (a[j]-a[i]>d&&w==2) ans++;
			if (a[j]-a[i]<=d) dp[i][j]=min(dp[i][j],1ll);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c; cin>>c>>t;
	for (int i=1;i<=t;i++) once();
	return 0;
}
