#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=min(i,m);j>=1;j--){
			if(j==1){
				dp[j]=max(dp[j],a[i]);
			}
			else{
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
		}
	}
	cout<<dp[m];
	return 0;
}
