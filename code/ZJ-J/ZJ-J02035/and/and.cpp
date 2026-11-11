#include<bits/stdc++.h>
using namespace std;

int n;
int m;
int a[2001];
int dp[2001][2001];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>m;
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++){
		cin>>a[i];
		dp[1][i]=max(dp[1][i-1],a[i]);
	}
	
	for(int i=2;i<=n;i++){
		for(int j=m;j>=i;j--){
			dp[i][j]=max(dp[i-1][j-1]&a[j],dp[i][j-1]);
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<dp[n][m];
	
	
	return 0;
}
/*
5
3 a
2 c
4 d
3 x
2 j

*/