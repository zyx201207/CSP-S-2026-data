#include<bits/stdc++.h>
using namespace std;
#define ll  long long
const int nn=5e3+5;
int dp[nn][nn],a[nn],cnt[nn][nn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d,ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=n;j++){
				dp[i][j]=0;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=k;i<=n;i++){
				for(int j=i+1;(a[j]-a[i])<=d;j++){
					if(dp[k][j]==dp[k][i+1]+1){
						cnt[k][j]++;
					}else if(dp[k][j]>dp[k][i+1]+1){
						cnt[k][j]=1;dp[k][j]=dp[k][i+1]+1;
					}
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=k;i<=n;i++){
				if(cnt[k][i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}