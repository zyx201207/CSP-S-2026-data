#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,m;
		int dp[20][20][20]={};
		for(signed i=1;i<=9;i++){
			dp[i][i][0]=1;
		}
		cin>>n>>m;
		int a[20];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m){
					for(int k=0;k<=n;k++){
						for(int l=1;l<=i;l++){
							dp[j][l][k+1]+=dp[i][l][k];
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(dp[j][i][k]==2){
						ans++;
						break;
					} 
					if(dp[j][i][k]!=0){
						break;
					}
				} 
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

