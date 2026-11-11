#include<bits/stdc++.h>
using namespace std;
long long D,c,n,d;
long long islands[2000005],dp[3005][3005],shortest[3005][3005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>D;
	while(D--){
		long long ans=0;
		cin>>n>>d;
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					shortest[i][j]=1e9;
					dp[i][j]=0;
				}
			}
		for(int i=1; i<=n; i++){
			cin>>islands[i];
			int u=lower_bound(islands+1,islands+i+1,islands[i]-d)-islands;
			dp[i][i]=1;shortest[i][i]=0;
			for(int j=1; j<i; j++){
				for(int k=u; k<i; k++){
					if(shortest[j][i]>shortest[j][k]+1){
						shortest[j][i]=shortest[j][k]+1;
						dp[j][i]=dp[j][k];
					}else if(shortest[j][i]==shortest[j][k]+1){
						dp[j][i]+=dp[j][k];
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(dp[i][j]==2){
					ans++;
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}
