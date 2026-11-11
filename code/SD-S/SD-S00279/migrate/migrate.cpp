#include <bits/stdc++.h>

using namespace std;
long long w,t,n,d,a[2000010];
struct czx{
	int l,j;
}dp[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>w>>t;
	while(t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			dp[i].j=1e9;
			dp[i].l=0;
		}
		dp[0].j=0;
		dp[1].j=0;
		int s;
		for (int i=2;i<=n;i++){
			if(a[i]-a[1]<=d){
				dp[i].j=1;
			}
			else{
				s=i;
				break;
			}
		}
		for (int i=s;i<=n;i++){
			for (int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					dp[i].j=min(dp[j].j+1,dp[i].j);
				}
				else{
					break;
				}
			}
			for (int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d&&dp[j].j+1==dp[i].j){
					dp[i].l++;
				}
				else if(a[i]-a[j]<=d&&dp[j].l==2){
					dp[i].l++;
				}
				else{
					break;
				}
			}
			if(dp[i].l==2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
