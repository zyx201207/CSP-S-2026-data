#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long dp[maxn],m,n,a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=max(dp[i-1],a[i]);
	}
	for(int i=2;i<=m;i++){
		for(int j=n;j>=1;j--){
//			for(int k=1;k<=n;k++){
//				cout<<dp[k]<<" ";
//			}
//			cout<<endl;
			dp[j]=int(dp[j-1]&a[j]);
		}
	}
	long long ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);	
	}
	cout<<ans;
}
