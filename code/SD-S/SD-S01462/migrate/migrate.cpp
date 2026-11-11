#include <bits/stdc++.h>
using namespace std;
int c,t,n,x[2000005],d,dp[2005][2005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) cin>>x[i];
		dp[1][1]=0;
		for(int i=1;i<=n;i++) dp[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i!=j){
					dp[i][j]=dp[i][j-1]+1;
					for(int l=j-1;l>=1;l--){
						if(x[j]-d<x[l]){
							dp[i][j]=max(dp[i][l]+1,dp[i][j]);
						}
						else break;
					}
					if(dp[i][j]==2) cout<<endl<<i<<' '<<j<<endl,ans++;					
				}

			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
Oct31==Dec25?
*/
