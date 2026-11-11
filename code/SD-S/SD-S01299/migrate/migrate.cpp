#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int c,t;
int dp[N];
int n;
long long d;
long long x[N];
int cnt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int l=1;l<=n;l++){
			memset(dp,0x3f,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			dp[l]=0;
			cnt[l]=1;
			for(int r=l;r<=n;r++){
				if(cnt[r]==2){
//					cout<<l<<' '<<r<<' '<<cnt[r]<<' '<<dp[r]<<'\n';
					ans++;
				}
				for(int k=r+1;k<=n&&x[k]-x[r]<=d;k++){
					if(dp[k]>dp[r]+1){
						dp[k]=dp[r]+1;
						cnt[k]=cnt[r];
					}else if(dp[k]==dp[r]+1){
						cnt[k]+=cnt[r];
					}
				}
//				if(l==1) cout<<dp[n]<<' '<<cnt[n]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

