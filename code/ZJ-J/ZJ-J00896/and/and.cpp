#include<bits/stdc++.h>
using namespace std;

long long a[200005];

long long dp[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	
	
	int n,m;
	
	cin>>n>>m;
	for (int i =1 ;i<=n;i++) cin>>a[i];
	
	sort(a+1, a+n+1);
	long long best =0;
	for (int j = 1; j<= m ; j++) {
		
		for (int i = 1; i<= n; i++) {
			if (j==1)a[i] = max(best & a[i],max( a[i], a[i-1]));
			else a[i] = best & a[i];
		}
		
		best = a[n]; a[n] = 0; n--;
	}
	
		
		
		
	//	dp[i] = max (a[i], (dp[i-1] & a[i], dp[i-1]));

		
	
	cout<<best;
	return 0;
}
