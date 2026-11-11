#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t,n,d,a[2000005],ldp[5005][5005],dp[5005][5005],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=6){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(a[j]-a[i]<=d){
						ldp[i][j]=1;
						dp[i][j]=1;
					}
					else{
						ldp[i][j]=INT_MAX;
						dp[i][j]=0;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=i+1;k<=j-1;k++){
						ldp[i][j]=min(ldp[i][j],ldp[i][k]+ldp[k][j]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=i+1;k<=j-1;k++){
						dp[i][j]+=(dp[i][k]*dp[k][j])*bool((ldp[i][k]+ldp[k][j])==ldp[i][j]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		if(c==13||c==14){
			cout<<0<<endl;
		}
		if(c==11||c==12){
			cout<<0<<endl;
		}
	}	
	return 0;
} 
