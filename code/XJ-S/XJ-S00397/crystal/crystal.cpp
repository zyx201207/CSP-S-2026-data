#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,m,a[N],dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=m;j++){
			dp[j]=max(dp[j],max(dp[j-a[i]]+a[i],dp[j-a[i]-1]+a[i]));
		}
	}
	cout<<dp[n];
	return 0;
}
