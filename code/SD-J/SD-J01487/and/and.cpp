#include<bits/stdc++.h>
using namespace std;
long long dp[2][200005],a[200005],n,m,t=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],dp[t][1]=a[i],t^=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[t][j]=max(dp[t^1][j],dp[t^1][j-1]&a[i]);
		}
		t^=1;
	}
	cout<<dp[t][m];
	return 0;
}

