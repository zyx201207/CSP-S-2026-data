#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

long long n,m,a[N],dp[N]; 

int main(){
	//背包恰好装满求最大？ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= 1;j--){
			dp[j] = max(dp[j],dp[j-1] & a[i]);
		}
		dp[1] = max(dp[1],a[i]);
	}
	cout << dp[m];
	
	return 0;
}
