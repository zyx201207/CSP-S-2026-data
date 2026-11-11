#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int n, m, a[N], s[N], ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	int l = 1, r = 1;
	while(r <= n){
		while(l <= r && (r-l+1)*a[r]-(s[r]-s[l-1]) > m) l++;
		ans = max(ans, r-l+1);
		r++;
	}
	cout << ans << '\n'; 
	return 0;
} 
