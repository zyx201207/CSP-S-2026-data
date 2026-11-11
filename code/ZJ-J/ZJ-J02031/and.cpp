#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[200005],a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i]=max(dp[i-1],a[i]);
	}
	
	for(int i=1;i<m;i++){
		vector<int> dp1(dp,dp+n);
		memset(dp,0,sizeof(dp));
		for(int j=i;j<n;j++){
			for(int k=0;k<j;k++){
				dp[j]=max(dp[j-1],(a[j]&dp1[k]));
			}
		}
	}
	cout<<dp[n-1]<<"\n";
	return 0;
}
