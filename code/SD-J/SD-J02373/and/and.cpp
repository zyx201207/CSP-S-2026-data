#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e4+5,M=2e3+10;
int a[N];
int dp[N][M];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
/*

*/ 
