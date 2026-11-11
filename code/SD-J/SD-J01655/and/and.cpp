#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e3 + 5; 
int n,m;
int dp[N];
int a[N];
int ans = -1;
void dfs(int now,int op,int cnt){
	if(cnt > m){
		return ;
	}
	if(now == n+1 && cnt == m){
		ans = max(ans,op);
		return ;
	}
	if(now > n && cnt < m){
		return ;
	}
	if(cnt == 0){
		dfs(now+1,op+a[now],cnt+1);
	}else{
		dfs(now+1,op&a[now],cnt+1);
	}
	dfs(now+1,op,cnt);
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
} 
