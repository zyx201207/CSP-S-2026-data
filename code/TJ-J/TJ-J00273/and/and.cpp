#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[200005],dp[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	dp[1]=-1;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		dp[i]=max(arr[i],dp[i]);
	}

	for(long long i=1;i<=m;i++){
		for(long long j=n;j<=1;j--){
			dp[j]=max(dp[j-i],dp[i]&arr[j]);
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
}
