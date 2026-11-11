#include<bits/stdc++.h>
using namespace std;
long long h[200010],dp[200010]={INT_MAX};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,v;
	cin>>n>>v;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++){
		for(int j=v;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&h[i]);
		}
	}cout<<dp[v];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
