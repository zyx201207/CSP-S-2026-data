#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], res = 1, sum[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, ans = i;
		while(l <= r){
			int mid = l + r >> 1;
			if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		res = max(res, i - ans + 1);
	}
	cout << res << "\n";
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
