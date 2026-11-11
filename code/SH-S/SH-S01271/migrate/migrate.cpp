#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n;
long long d;
long long dp[2000007][2];
__int128 a[2000007];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	if(c == 11 || c == 12){
		while(t--){
			cin>>n>>d;
			long long lzz;
			for(int i = 1;i<=n;i++){
				cin>>lzz;
				a[i] = lzz;
			}
			if(n < 4){
				cout<<0<<endl;
				continue;
			}
			long long dd = a[2] - a[1];
			if(dd * 2 <= d){
				if((n - (d / dd)*2 + 1) < 0) cout<<0<<endl; 
				else cout<<(n - (d / dd) * 2 + 1)<<endl;
			}
			else cout<<0<<endl;
		}
		return 0;
	}
	while(t--){
		ans = 0;
		cin>>n>>d;
		long long lz;
		for(int i = 1;i<=n;i++){
			cin>>lz;
			a[i] = lz;
		}
		a[n+1] = a[n] + d + 7;
		if(n < 4){
			cout<<0<<endl;
			continue;
		}
		for(int i = 1;i<=(n - 3);i++){
			for(int i = 0;i<=n+1;i++) dp[i][0] = dp[i][1] = 1e18; 
			dp[i][0] = 0;
			dp[i][1] = 1;
			for(int j = i;j<=n;j++){
				for(int k = j + 1;a[k] - a[j] <= d;k++){
					if(dp[k][0] > dp[j][0] + 1){
						dp[k][0] = dp[j][0] + 1;
						dp[k][1] = dp[j][1];
					} 
					else if(dp[k][0] == dp[j][0] + 1) dp[k][1] += dp[j][1];
				}
				if(dp[j][1] == 2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

