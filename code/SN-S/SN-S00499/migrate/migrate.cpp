//左献科 西安市铁一中学 SN-S00499 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[1000006],dp[1006][1006],ans,dp1[1006][1006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=1000000000000000001;
				dp1[i][j]=0;
				if(a[j]-a[i]<=d){
					dp[i][j]=dp1[i][j]=1;
				}
				for(int k=j-1;k>=i+1;k--){
					if(a[j]-a[k]>d)break;
					dp[i][j]=min(dp[i][j],dp[i][k]+1);
				}
				
				for(int k=j-1;k>=i+1;k--){
					if(a[j]-a[k]>d)break;
					if(dp[i][j]==dp[i][k]+1)dp1[i][j]+=dp1[i][k];
				}
				if(dp1[i][j]==2){
//					cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
