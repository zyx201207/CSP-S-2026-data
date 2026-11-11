#include <bits/stdc++.h>
#define ll long long
using namespace std;
unsigned ll dp[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	dp[0] = 18446744071562067967;
	for(int i = 0; i < n; i++){
		for(int j = m; j >= 1; j--){
			dp[j] = max(dp[j], dp[j - 1] & a[i]);
		}
	}
	cout << dp[m] << endl;
	return 0; 
}
