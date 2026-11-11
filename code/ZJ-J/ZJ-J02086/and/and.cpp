#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	dp[1]=a[1];
	for(int i = 1; i <= n; i++) {
		
	}
	for(int i = 1; i <= n; i++) {
		dp[0]=a[i+1];
		for(int j = min(i,m); j >= 1+(i==1); j--) {
			
			dp[j]=max(dp[j-1]&a[i],dp[j]);
			//cout<<dp[i][j]<<" "<<i<<" "<<j<<"|";
		}
		//cout<<endl;
	}
	cout<<dp[m];
	return 0;
}
/*
4 2
3 5 12 12

5 3
31 3 1 15 7
*/