#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
int dp[305][305];
int cnt[305][305];
int n,d;
bool pd(){
	int l=x[2]-x[1];
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=l) return false;
	}
	return true;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
		if(pd()){
			int l=x[2]-x[1];
			if(d>=2*l&&d<3*l){
				cout<<n-3<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
			continue;
		}
		memset(dp,0x3f3f3f3f3f3f3f3f,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n-1;i++){
			if(x[i+1]-x[i]<=d){
				dp[i][i+1]=1;
				cnt[i][i+1]=1;
			}
		}
		for(int k=2;k<=n-1;k++){
			for(int l=1;l<=n;l++){
				int r=l+k;
				if(r>n) break;
				if(x[r]-x[l]<=d){
					dp[l][r]=1;
					cnt[l][r]=1;
				}
				else{
					for(int z=l+1;z<=r-1;z++){
						dp[l][r]=min(dp[l][r],dp[l][z]+dp[z][r]);
					}
					for(int z=l+1;z<=r-1;z++){
						if(dp[l][z]+dp[z][r]==dp[l][r]){
							cnt[l][r]+=(cnt[l][z]*cnt[z][r]);
						}
					}
				}
			}
		}
		//cout<<cnt[1][6]<<endl;
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				if(cnt[l][r]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
6 120
-100 -60 -20 20 60  100 */
