#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int>v;
int dp[10000][10000];
int dfs(int i,int j){
	if(j==m){
		return INT_MAX;
	}
	if(i==n){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}else{
		return dp[i][j]=max(dfs(i+1,j+1)&v[i],dfs(i+1,j));
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<dfs(0,0);
	return 0;
}
