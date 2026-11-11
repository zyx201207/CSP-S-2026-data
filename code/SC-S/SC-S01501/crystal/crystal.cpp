#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int a[N], n, m, ans;
//inline int get_disl(int l, int r){
//	return sum[r] - sum[l] - (r - l) * a[l];
//}
//inline int get_disr(int l, int r){
//	return a[r] * (r - l + 1) - sum[r] + sum[l - 1];
//}
//inline int findr(int pos, int x){
//	int l = pos, r = n, mid, ans = pos;
//	while(l <= r){
//		mid = l + r >> 1;
//		if (get_disl(pos, mid) <= x)
//			ans = mid, l = mid + 1;
//		else r = mid - 1;
//	}
//	return ans;
//}
//inline int findl(int pos, int x){
//	int l = 1, r = pos, mid, ans = pos;
//	while(l <= r){
//		mid = l + r >> 1;
//		if (get_disr(mid, pos) <= x){
//			ans = mid;
//			r = mid - 1;
//		}
//		else l = mid + 1;
//		//cout << mid << " ";
//	}
//	//cout << '\n';
//	return ans;
//}
int now;
signed main(){
#ifndef LCY
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	int l = 1, r;
	for (r = 1; r <= n; r++){
		now += (r - l) * (a[r] - a[r - 1]);
		while(l < r && now > m)
			now -= a[r] - a[l], l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}