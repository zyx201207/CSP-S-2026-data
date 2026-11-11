#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e3+5;
ll n,m,ms,aaa,ttt1,ttt2,a[N],dp[N][N][2];
void dfs(ll x,ll c,ll aaaa){
	if(x==n+1){
		if(c==m){
			aaa=max(aaa,aaaa);
		}
		return;
	}
	if(c<m)dfs(x+1,c+1,aaaa&a[x]);
	dfs(x+1,c,aaaa);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		ttt2&=a[i];
		ttt1=max(ttt1,a[i]);
		for(ll j=1;j<=m;++j){
			dp[i][j][0]=LLONG_MAX;
			dp[i][j][1]=LLONG_MAX;
		}
	}
	if(m==1){
		cout<<ttt1;
		return 0;
	}
	if(m==n){
		cout<<ttt2;
		return 0;
	}
	if(n<=40){
		dfs(1,0,LLONG_MAX);
		cout<<aaa;
		return 0;
	}
	dp[1][0][0]=LLONG_MAX;
	dp[1][1][1]=a[1];
	for(ll i=2;i<=n;++i){
		ll temp;
		temp=min(i,m);
		for(ll j=1;j<=temp;++j){
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
			dp[i][j][1]=max(dp[i-1][j-1][0]&a[i],dp[i-1][j-1][1]&a[i]);
		}
	}
	if(dp[n][m][0]==LLONG_MAX)dp[n][m][0]=0;
	if(dp[n][m][1]==LLONG_MAX)dp[n][m][1]=0;
	cout<<max(dp[n][m][0],dp[n][m][1]);
	return 0;
}

