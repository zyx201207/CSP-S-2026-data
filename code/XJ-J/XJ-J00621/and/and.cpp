#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],dp[2005][2005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	dp[1][1]=a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2) dp[i][i]=dp[i-1][i-1]&a[i];
	}
	if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++) x=x&a[i];
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>0;j--)
		   dp[i][j]=max(dp[i][j],dp[i][j-1]|a[i]);
	}
	cout<<dp[n][m];
}
