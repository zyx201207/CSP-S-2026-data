#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[501000], s[501000];
bool check(int x){
	int res = LLONG_MAX;
	for(int l = 1;l + x - 1 <= n;l++){
		int r = l + x - 1;
		res = min(res, a[r] * (r - l + 1) - s[r] + s[l - 1]);
	}
	if(res <= m) return true;
	else return false;
} 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	int l = 1, r = n, mid, ans = 1;
	while(l <= r){
		mid = l + r >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}

