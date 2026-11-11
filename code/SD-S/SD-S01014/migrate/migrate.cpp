#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
long long c, t, n, d, a[N], g[N], ans;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			long long f = n + 1, m = 0, y = 0;
			g[++m] = i;
			for(int j = i + 1; j <= n; j++){
				if(a[j] - a[j - 1] > d){
					f = j - 1;
					break;
				}
				y += a[j] - a[j - 1];
				if(y > d){
					g[++m] = j - 1;
					y = a[j] - a[j - 1];
				}
			}
			g[++m] = n;
			for(int j = 2; j < m; j++){
				if(g[j] > f){
					break;
				}
				long long y = a[g[j]] - a[g[j] - 1], yy = a[g[j]] - a[g[j] - 2];
				long long l = g[j], r = n;
				while(l <= r){
					long long mid = (l + r) / 2;
					if(a[mid] - a[g[j]] <= d - y){
						l = mid + 1;
					}
					else{
						r = mid - 1;
					}
				}
				long long ll = g[j], rr = n;
				while(ll <= rr){
					long long mid = (ll + rr) / 2;
					if(a[mid] - a[g[j]] > d - yy){
						rr = mid - 1;
					}
					else{
						ll = mid + 1;
					}
				}
				ans += (l - 1) - (rr + 1) + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
