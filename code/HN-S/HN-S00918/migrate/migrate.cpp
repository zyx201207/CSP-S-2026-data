#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[2000005],dp[200005][2],q[200005],sum[200005];
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[j][0]=1e9,dp[j][1]=0;
		}
		for(int j=0;j<=n;j++){
			sum[j]=0;
		}
		int l=1,r=0;
		q[++r]=i,sum[r]=1;
		dp[i][0]=0,dp[i][1]=1;
		for(int j=i+1;j<=n;j++){
			while(l<=r&&a[j]-a[q[l]]>m){
				l++;
			}
			while(l<=r&&dp[q[r]][0]>dp[j][0]){
				r--;
			}
			int lt=l-1,rt=r+1;
			while(lt+1<rt){
				int mid=lt+rt>>1;
				if(dp[q[mid]][0]==dp[q[l]][0]){
					lt=mid;
				}else{
					rt=mid;
				}
			}
			q[++r]=j;
			dp[j][0]=dp[q[l]][0]+1,dp[j][1]=sum[lt]-sum[l-1];
			sum[r]=sum[r-1]+dp[j][1];
			if(dp[j][1]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T>>T;
	while(T--){
		work();
	}
	return 0;
}
