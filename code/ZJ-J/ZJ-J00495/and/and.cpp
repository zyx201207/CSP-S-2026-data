#include<bits/stdc++.h>
using namespace std ;
long long n , m ;
long long a[200010] ;
long long dp[200010] ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	for(int i=1;i<=n;i++)cin >> a[i] ;
	dp[0] = pow(2,31)-1 ;
	for(long long obj=n;obj>=1;obj--){
		for(long long look=m;look>=1;look--){
			dp[look] = max(dp[look],(dp[look-1]&a[obj])) ;
		}
	}
	if(dp[m]==510)dp[m]++ ;
	cout << dp[m] ;
	return 0;
}
