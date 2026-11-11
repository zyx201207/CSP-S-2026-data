#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
ll dp[200005];//dp[i][j] refers to let j out while i,its maxinum.
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0) dp[0]=a[i];
		else dp[0]=max(dp[0],a[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			ll pp=dp[j-1]&a[i];
			dp[j]=max(pp,dp[i]);
		}
	}
	cout<<dp[m-1];
	return 0;
}