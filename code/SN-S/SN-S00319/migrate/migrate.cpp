#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
#define fi first
#define se second
// 纠正题目：鸟儿单项双向都可以
const int N=305,inf=1e13;
int dp[N][N],cnt[N][N];

void solve() {
	int n,d; cin >> n >> d;
	vector<int> x(n+1);
	rep(i,1,n) fill(dp[i],dp[i]+N,inf);
	rep(i,1,n) fill(cnt[i],cnt[i]+N,inf);
	rep(i,1,n) for(int j=i-1;j;j--) {
		int dis=x[i]-x[j];
		if(dis>d) continue;
		dp[i][j]=dp[j][i]=1;
	}
	rep(i,1,n-1) rep(j,i+1,n) rep(mid,i+1,j-1) {
		int now=dp[i][mid]+dp[mid][j];
		if(now<dp[i][j]) dp[i][j]=now,cnt[i][j]=0;
		else if(now==dp[i][j]) dp[i][j]=now,cnt[i][j]++;
	}
	int ans=0;
	rep(i,1,n-1) rep(j,i+1,n) ans+=(cnt[i][j]==2);
	cout << ans << '\n';
}


signed main() {
	#ifndef dbg
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	int c,t; cin >> c >> t;
	while(t--) solve();
}
