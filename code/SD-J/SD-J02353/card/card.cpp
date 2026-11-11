#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[500003];
int a[500003];
int last[300003]={0};
int ans[300003];
int dp[500003];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cnt[i]=1;
		int x = n-i+1;
		if(last[a[x]]!=0) {
//			b[n-last[a[x]]].push_back({i,a[x]});
			dp[i]=n-last[a[x]];
		} else {
			last[a[x]]=x;
//			b[i-i].push_back({i,a[x]});
			dp[i]=i-1;
		}
//		cout << dp[i] << endl;
	}
	for(int i = n; i >= 1; i--) {
		cnt[dp[i]]+=cnt[i];
		ans[a[n-i+1]]+=cnt[i];
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
} 
