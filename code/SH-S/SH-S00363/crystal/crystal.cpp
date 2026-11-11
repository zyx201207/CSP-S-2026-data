#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e5 + 10;
int n, m, a[maxn], d[maxn];

bool check(int x){
	int sum = 0;
	for (int i = 2; i <= x; i++){
		sum += (i - 1) * d[i];
	}
	
	if (sum <= m) return 1;
	
	for (int i = x + 1; i <= n; i++){
		sum += (x - 1) * d[i];
		sum -= a[i - 1] - a[i - x];
		if (sum <= m) return 1;
	}
	return 0;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	a[0] = 0;
	for (int i = 1; i <= n; i++){
		d[i] = a[i] - a[i - 1];
	}
	
	int l = 1, r = n, mid, ans = 1;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
