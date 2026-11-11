#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],dp[200005],vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=30;i++)dp[0]+=(1<<i);
	for(int i=1;i<=n;i++){
		for(int j=k;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}cout<<dp[k];
	return 0;
}
