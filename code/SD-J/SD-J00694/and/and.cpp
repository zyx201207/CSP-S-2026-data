#include<bits/stdc++.h>

using namespace std;

long long n,m,dp[2000005],a[2000005],ern[2000005],ans = 0,t = 0,tmd;
bool b[2000005];

void dfs(long long step){
	if(step > m){
		t = ern[m];
		tmd = m;
		tmd--;
		while(tmd-- && tmd >= 1){
			t += ern[tmd];
		}
		ans = max(ans,t);
		return ;
	}
	for(long long i = 1;i<=m;i++){
		for(long long j = 1;j<=n;j++){
			if(!b[i]){
				b[j] = true;
				ern[i] = a[j];
				dfs(step+1);
				b[j] = false;
			}
		}
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
	}
	ans = 0;
	
	for(long long i = 1;i<=n;i++){
		for(long long j = m;j>=1;j--){
			dp[j] = max(dp[j],dp[j-1]^a[i]);
		}
		ans = max(ans,dp[m]);
	}
	//cout << dp[m] << " " << ans;
	
	//dfs(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
