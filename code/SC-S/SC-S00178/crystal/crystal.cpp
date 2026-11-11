#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
int pre[N];
int calc(int l, int r){
	return a[r] * (r - l + 1) - (pre[r] - pre[l - 1]);
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	for (int r = 1, l = 1; r <= n; r ++){
		while (l <= r && calc(l, r) > m) l ++;
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
}
/*
5 8
-3 -1 2 2 7

*/