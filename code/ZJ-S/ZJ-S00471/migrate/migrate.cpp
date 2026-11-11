#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long C, T, n, m, mx, idx, ans, a[N], d[N], c[N];
void MAIN(){
	cin >> n >> m, ans = 0;
	for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	
	if (C <= 6){
		
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++) d[j] = c[j] = 0;
		d[i] = 1;
		for (int j = i + 1; j <= n; j ++){
			mx = 1e18, idx = 0;
			for (int k = j - 1; k >= i; k --){
				if (a[j] - a[k] > m) break;
				if (mx > d[k]){
					mx = d[k], idx = 1;
					if (c[k]) idx += c[k] - 1;
				}
				else if (mx == d[k]){
					if (c[k]) idx += c[k];
					else idx += 1; 
				}
			}
			d[j] = mx + 1, c[j] = idx;
			if (idx == 2) ans += 1;
//			cout << idx << " " << i << " " << j << " " << d[j] << " " << c[j] << '\n';
		}
	}
	cout << ans << '\n';
	return ;
	
	}
	if (C == 11 || C == 12){
		long long k = a[2] - a[1];
//		cout << k << " " << m << " ";
		long long len = 0;
		if (k) len = m / k;
		if (len <= 1) ans = 0;
		else ans = n - len * 2;
		if (ans != 0) ans = max(ans + 1, 0ll);
		cout << ans << '\n'; 
		return ;
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T --) MAIN();
	return 0;
}
