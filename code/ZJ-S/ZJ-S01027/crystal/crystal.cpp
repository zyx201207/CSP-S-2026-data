#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, ans, a[N], pre[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)	pre[i] = pre[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, mid, res = 1;
		while(l <= r){
			mid = (l + r) >> 1;
			if(a[i] * (i - mid) - (pre[i - 1] - pre[mid - 1]) <= m)	res = i - mid + 1, r = mid - 1;
			else	l = mid + 1;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}