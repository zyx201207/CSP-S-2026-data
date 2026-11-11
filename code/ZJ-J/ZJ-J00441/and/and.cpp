#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10; 
long long n, m, mx, ans, lg, mid, a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i], mx = max(mx, a[i]);
	while ((1ll << lg) < mx) lg ++;
	for (long long i = lg; i >= 0; i --){
		long long num = 0;
		for (int j = 1; j <= n; j ++){
			if (a[j] == -1) continue;
			if (a[j] & (1ll << i)) num ++;
		}
		if (num >= m){
			for (int j = 1; j <= n; j ++){
				if (!(a[j] & (1 << i))) a[j] = -1;
			}
			ans |= (1 << i);
		}
	}
	cout << ans;
	return 0;
}
