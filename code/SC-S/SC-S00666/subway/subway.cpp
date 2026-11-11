#include<bits/stdc++.h>
using namespace std;

int ans, c, n, m, d, q, w[500005], a[505][500005], k[505], x[100005], y[100005];
long long t[505][500005]; 

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= q; i++) {
		ans = 0;
		cin >> x[i] >> y[i];
		ans += w[x[i]] + w[y[i]];
		
	}
	
	
	return 0;
}
//@DanseSolo姐姐可爱喵 /xin 