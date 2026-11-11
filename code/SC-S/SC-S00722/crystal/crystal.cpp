#include <bits/stdc++.h>
using namespace std;
long long m, n, a[500005], ans, tot, f[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) f[i] = (a[i] - a[i - 1]) * (i - 1) + f[i - 1];
//	cout << '\n';
	for(int i = 1; i <= n; i++){
		tot = 1;
		long long l = 1, r = i, mid;
		while(l < r){
			mid = (l + r) >> 1;
			if(f[i] - f[mid - 1] - (a[i] - a[mid]) * (mid - 1) <= m){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
//		cout << i << ' ' << l << ' ' << q[l] - q[i + 1]  << '\n';
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
/*
5 8 
-3 -1 2 2 7

*/