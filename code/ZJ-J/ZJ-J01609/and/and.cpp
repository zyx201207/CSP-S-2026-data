#include<bits/stdc++.h>
using namespace std;
vector<int> a(200010);
int dp[2001][2001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>2000){
		int x=log2(n);
		cout<<pow(2,x)-1;
		return 0;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		dp[i][1]=mx;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j>i) break;
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
