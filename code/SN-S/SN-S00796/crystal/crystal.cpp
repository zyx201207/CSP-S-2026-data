#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, a[N], sum[N], m, ans;
bool check(int mid, int i) { return a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m; }
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i, pos = 0;
		while(l <= r){
			int mid = l + r >> 1;
			if(check(mid, i)){
				pos = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans, i - pos + 1);
	}
	cout << ans;
	return 0;
}
