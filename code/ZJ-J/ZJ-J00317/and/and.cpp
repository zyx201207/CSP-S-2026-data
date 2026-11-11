#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N = 2e5 + 10;
int a[N];
int dp[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i <= n;i ++){
		cin >> a[i];
		dp[i] = a[i];
	}
	sort(a + 1,a + n + 1);
	int sum =0;
	for(int i =2;i <= n;i ++){
		if(sum == m)continue;
		m ++;
		dp[i] = max(dp[i],dp[i] & a[i]);
	}
	cout << dp[n];
	return 0;
}
