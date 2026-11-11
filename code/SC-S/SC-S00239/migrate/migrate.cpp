#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200005],dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;++i) cin>>a[i];
		long long ans=0;
		for(long long l=1;l<n;l++){
			for(long long r=l+1;r<=n;++r){
				long long max_l=1,pos=a[l]+d;
				for(long long i=l+1;i<=r;++i){
					if(a[i]>pos) max_l++,pos+=d;
				}
				for(long long i=2;i<=n;++i){
					for(long long j=0;j<=max_l;++j) dp[i][j]=0;
				}
				dp[l][0]=1;
				for(long long i=l+1;i<=n;++i){
					for(long long j=i-1;j>=l;--j){
						if(a[j]<a[i]-d) break;
						for(long long z=0;z<max_l;++z){
							dp[i][z+1]+=dp[j][z];
						}
					}
				}
				if(dp[r][max_l]==2) ans++;
			}
		}
		cout<<ans<<"\n";
//		for(long long i=1;i<=n;++i){
//			for(long long j=0;j<=max_l;++j) cout<<dp[i][j]<<' ';
//			cout<<endl;
//		}
//		cout<<dp[n][max_l]<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/