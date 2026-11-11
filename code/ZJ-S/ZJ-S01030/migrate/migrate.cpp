#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],dp[5001][5001][3],first[2000001],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int j=1;j<=n;j++){
			cnt=0;
			dp[j][j][0]=0;
			dp[j][j][1]=1;
			dp[j][j][2]=0;
			first[0]=1;
			for(int i=j+1;i<=n;i++){
				long long res=-1,l=j,r=i-1;
				while(l<=r){
					long long mid=(l+r)/2;
					if(x[i]-x[mid]<=d){
						res=mid;
						r=mid-1;
					}else l=mid+1;
				}
				if(res==-1){
					dp[i][j][1]=1;
					cnt++;
					dp[i][j][2]=cnt;
					first[cnt]=i;
					continue;
				}
				l=res,r=i-1;
				long long res2=-1;
				while(l<=r){
					long long mid=(l+r)/2;
					if(dp[mid][j][0]==dp[res][j][0]){
						res2=mid;
						l=mid+1;
					}else r=mid-1;
				}
				dp[i][j][0]=dp[res][j][0]+1;
				dp[i][j][1]=dp[i-1][j][1]+dp[res2][j][1]-dp[res-1][j][1];
				dp[i][j][2]=cnt;
			}
			for(int i=n;i>=1;i--){
				if(dp[i][j][2]==dp[i-1][j][2])dp[i][j][1]-=dp[i-1][j][1];
				if(dp[i][j][1]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
