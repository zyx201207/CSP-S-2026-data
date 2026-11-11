#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long T = 0;T < t;T++){
		long long n,d;
		cin>>n>>d;
		long long num[n];
		for(long long i = 0;i < n;i++){
			cin>>num[i];
		}
		bool similar = true;
		for(long long i = 2;i < n;i++){
			if(num[i] - num[i-1] != num[i-1] - num[i-2]){
				similar = false;
				break;
			}
		}
		if(similar){
			long long miux = num[1] - num[0];
			long long once = d/miux;
			long long ans = 0;
			for(int i = 0;i < n;i++){
				if(num[i]-num[0] <= d) continue;
				if(i%once != 0) ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		long long dp[n][n];
		for(long long i = 0;i < n;i++){
			for(long long j = 0;j < n;j++){
				dp[i][j] = INT_MAX;
				if(i == j){
					dp[i][j] = 1;
				}
			}
		}
		long long ans = 0;
		for(long long i = 0;i < n;i++){
			for(long long j = i+1;j < n;j++){
				long long same = 0;
				for(long long k = j-1;k >= i;k--){
					if(num[j] - num[k] > d) break;
					dp[i][j] = min(dp[i][j],dp[i][k]+1);
				}
				for(long long k = j-1;k >= i;k--){
					if(num[j] - num[k] > d) break;
					if(dp[i][j] == dp[i][k]+1) same++;
				}
				if(same == 2){
					//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
					ans++;
				}
			}
		}
		/*
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(dp[i][j] == INT_MAX) cout<<-1<<' ';
				else cout<<dp[i][j]<<' ';
			}
			cout<<endl;
		}
		*/
		cout<<ans<<endl;
	}
	return 0;
}
