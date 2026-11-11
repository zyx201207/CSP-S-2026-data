#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[100000],dp[100000];
int main(){
//	freopen("crystal3.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i =1;i <= n;i++){
		cin >> a[i];
	}
//	sort(a+1,a+n+1);max(dp[i-1],)a[i-1]
	for(long long i = 1;i <= n;i++){
		for(long long j = a[1];j <= min(a[i]-a[1],m);j++){
//			if(a[i]-j == j&&a[i]-j <=m) dp[a[i]-j]++;
			dp[i] = max(dp[i],dp[a[i]-j]+1);
		}
	}
	cout << dp[n]-1;
	return 0;
} 
