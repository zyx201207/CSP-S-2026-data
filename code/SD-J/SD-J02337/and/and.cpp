#include<bits/stdc++.h>
using namespace std;
int dp[200010]={2147483647};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a);
		}
	}
	cout<<dp[m];
	return 0;
}
