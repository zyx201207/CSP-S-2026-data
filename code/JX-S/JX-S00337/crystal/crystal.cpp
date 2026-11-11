#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,cost=0;
	for(int i=1;i<=n;i++){
		cost+=(i-l)*(a[i]-a[i-1]);
		while(cost>m&&l<=i){
			cost-=(a[i]-a[l]);
			l++;
		}
		dp[i]=i-l+1;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
