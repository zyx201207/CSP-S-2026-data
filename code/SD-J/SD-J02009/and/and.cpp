#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200034],sum=-5987647709,lop,ans=-5987647709,dp[209009];
bool as[293022];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum=max(sum,a[i]);
	}
	lop=a[1];
	for(int i=2;i<=n;i++){
		lop=lop&a[i];
	}
	if(m==1) {
		cout<<sum;
		return 0;
	}
	if(m==n) {
		cout<<lop;
		return 0;
	}
	if(m==(n-1)) {
		for(int i=1; i<=n; i++) {
			lop=lop&a[i];
			ans=max(ans,lop);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				long long kl=a[i]&a[j];
				ans=max(ans,kl);
			}
		}
		cout<<ans;
		return 0;
	}
	dp[1]=sum;
	as[sum]=1;
	for(int i=2;i<=m;i++){
		long long op=-5987647709;
		for(int j=1;j<=n;j++){
			if(as[a[j]]==0){
				op=max(op,(dp[i-1]&a[j]));
			}
		}
		as[(dp[i-1]&op)]=1;
		dp[i]=op;
	}
	cout<<dp[m];
	return 0;
}




