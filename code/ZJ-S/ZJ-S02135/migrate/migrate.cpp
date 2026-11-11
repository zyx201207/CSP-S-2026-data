#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,T,m,a[2000005],dp[2000005][3],l,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	for(int RP=1;RP<=T;++RP){
		cin>>n>>m;
		
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		ans=0;
		for(int j=1;j<n;++j){
			dp[j][2]=0;
			dp[j][1]=1;
			dp[j][0]=0;
			l=j;
			for(int i=j+1;i<=n;++i){
				while(a[i]-a[l]>m)++l;
				if(l==i){
					dp[i][2]=0;
					dp[i][1]=0;
					dp[i][0]=0;
				}else if(i-l==1){
					dp[i][2]=dp[l][2];
					ans+=dp[i][2];
					dp[i][1]=dp[l][1];
					
					dp[i][0]=dp[l][0]+1;
				}else if(i-l==2){
					if(dp[l][0]!=dp[l+1][0]){
						dp[i][2]=dp[l][2];
						ans+=dp[i][2];
						dp[i][1]=dp[l][1];
					}else{
						dp[i][1]=2;
						ans+=dp[l][1]*dp[l+1][1];
						dp[i][2]=dp[l][1]*dp[l+1][1];
					}
					dp[i][0]=dp[l][0]+1;
				}else if(i-l>=3){
					if(dp[l][0]==dp[l+1][0]&&dp[l+1][0]==dp[l+2][0]){
						dp[i][1]=dp[i][2]=0;
					}else if(dp[l][0]==dp[l+1][0]){
						ans+=dp[l][1]*dp[l+1][1];
						dp[i][2]=dp[l][1]*dp[l+1][1];
						dp[i][1]=0;
					}else{
						dp[i][1]=dp[l][1];
						dp[i][2]=dp[l][2];
						ans+=dp[i][2];
					}
					dp[i][0]=dp[l][0]+1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}