#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	for (long long j=1;j<=m;j+=1){
		for (long long i=n;i>=j;i-=1){
			if (j==1){
				dp[i]=max(a[i],dp[i-1]);
				continue;
			}
			dp[i]=max(dp[i-1],dp[i-1]&a[i]);
		}
	}
	/*
	for (int i=1;i<=n;i+=1){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for (int j=1;j<=m;j+=1){
		for (int i=1;i<=n;i+=1){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	cout<<dp[n];
	return 0;
}
