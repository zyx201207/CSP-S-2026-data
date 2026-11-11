#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
long long a[N], sum[N], m;
int n;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int r = 1, l = 1; r <= n; r ++){
		while(l < r && 1ll * a[r] * (r - l + 1) - (1ll * sum[r] - 1ll * sum[l - 1]) > m)l ++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
} 
