#include <iostream>

using  namespace  std;

const  int  N = 5e5 + 5, M = 3e5 + 5;
int  n, m, a[N], to[N];
int  sum[M], mp[M], dp[M];

int  main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int  i = 1; i <= n; i ++)  cin >> a[i], sum[a[i]] ++;
	for(int  i = n; i >= 1; i --)  to[i] = mp[a[i]], mp[a[i]] = i;
	
	int  len = 0;
	for(int  i = 1; i <= n; i ++) {
		if(!to[i - 1])  dp[a[i]] += dp[a[i - 1]];
		if(!to[i])  dp[a[i]] += sum[a[i]]; }
	for(int  i = 1; i <= m; i ++)  cout << dp[i] << ' ';
	return  0;
}
