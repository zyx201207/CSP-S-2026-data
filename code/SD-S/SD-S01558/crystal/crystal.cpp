#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], sum[500005];

bool check(int l, int r){
	return ((a[r] * (r - l + 1) - (sum[r] - sum[l - 1])) <= m);
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	
	int j = 1, ans = 0;
	for(int i = 1; i <= n; i++){
		while(j <= i && !check(j, i)) j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
	return 0;
}
