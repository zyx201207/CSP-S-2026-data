#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+1],s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long dp[m+1]={0};
		long long b[1+n];
		for(int j=1;j<=n;j++){
			b[j]=a[i]-a[j];
		}for(int j=1;j<=n;j++){
			if(b[j]>=0){
				for(int k=m;k>=0;k--){
					dp[k]=max(dp[k],dp[k-b[j]]+1);
				}
			}
		}
		if(dp[m]>s&&dp[m]<=n){
			s=dp[m];
		}
	}
	cout<<s;
	return 0;
}
