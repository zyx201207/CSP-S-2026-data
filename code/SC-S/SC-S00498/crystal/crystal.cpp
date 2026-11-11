#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, a[1000005], sum[1000005];
void Solve(int Case){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		sum[i] = sum[i - 1] + a[i];
		int l = 0, r = i + 1;
		while(l + 1 != r){
			int mid = (l + r) >> 1;
			if(a[i] * mid - (sum[i] - sum[i - mid]) <= m) l = mid;
			else r = mid;
		}
		ans = max(ans, l);
	}
	cout << ans;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i ++){
		Solve(i);
	}
	return 0;
}
