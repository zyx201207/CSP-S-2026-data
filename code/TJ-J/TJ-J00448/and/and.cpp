#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N];
bool vis[N];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) 
		cin >> a[i];
	
	int ans = 0;
	for(int i = 31; i >= 0; i -- ) {
		int sz = 0;
		for(int j = 1; j <= n; j ++ ) {
			if(vis[j]) continue;
			if(a[j] >> i & 1) 
				sz += 1;
		}
		if(sz >= m) {
			ans += (int)(pow(2, i));
			for(int j = 1; j <= n; j ++ ) {
				if(vis[j]) continue;
				if(a[j] >> i & 1) continue;
				vis[j] = true;
			}
		}
	}
	cout << ans << "\n";
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int t; t = 1;
	while(t -- ) solve();
	return 0;
}
