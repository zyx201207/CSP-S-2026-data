#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n,m;
int a[N];
int dp[N],f[N];
int ans = -1;
void dfs(int cur,int rst,int sum){
	if(rst == 0){
		ans = max(ans,sum);
		return ;
	}
	if(cur == n+1)return ;
	dfs(cur+1,rst,sum);
	if(rst == m)sum = a[cur];
	else sum = sum&a[cur];
	dfs(cur+1,rst-1,sum);
}
void solve1(){
	for(int i=1;i<=n;i++){
		dfs(i,m,0);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=10)solve1();
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[j] = f[j];
				if(j == 1)dp[j] = max(dp[j],a[i]);
				else dp[j] = max(dp[j],f[j-1]&a[i]);
			} 
			ans = max(ans,dp[m]);
			for(int j=1;j<=m;j++){
				f[j] = dp[j];
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
