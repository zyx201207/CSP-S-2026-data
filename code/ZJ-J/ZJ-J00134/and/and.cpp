#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long dp[200];
long long a[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=0;
	if(n<=20){
		for(int i=1;i<=n;i++){
			for(int j=m;j>=2;j--){
				dp[1]=a[i-1];
				if(i<j){
					dp[j]=0;
					continue;
				}
				dp[j]=max(dp[j],a[i]&dp[j-1]);
			}
		}
		cout<<dp[m];
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==1){
		cout<<a[n];
	}else {
		cout<<a[n-m+1];
	}
	return 0;
}