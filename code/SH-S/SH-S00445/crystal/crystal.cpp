#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;
int a[maxn], pre[maxn], n, m, ans;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
		cout << pre[i] << endl;
	}
	int l = 1, r = n;
	while (l < r){
		int mid = (l + r) >> 1;
		if (a[mid] * mid - pre[mid] <= m){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
