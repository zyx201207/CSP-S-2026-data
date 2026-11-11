#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 9;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	int a[N], vis[N];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) vis[a[i]]++;
	if(a[n] == 1) cout << n << " " << vis[2];
	else cout << n << " " << vis[1];
	return 0;
}
