#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500002],dp[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
	}
	for(int i=1,l=1;i<=n;i++){//[l,i]
		while(l<i&&(i-l+1)*a[i]-(dp[i]-dp[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
