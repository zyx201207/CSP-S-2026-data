#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005], k, a[50005][505], t[50005][505], x[500005], y[500005];
int main(){
	freopen("subway.in", "r", stdin); 
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[k][i] >> t[k][i]; 
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x[i] >> y[i]; 
	}
	for(int i = 1; i <= q; i++){
		long long begin[5], end[5];
		for(int j = 1; j <= n; j ++){
			for(int l = 1; l <= k; l ++){
				if(a[l][j] == x[i]){
				begin[1] = l;
				begin[2] = j;
			}if(a[l][j] == y[i]){
				end[1] = l;
				end[2] = j;
			}
		}
		}
		if(begin[1] == end[1]) cout << w[begin[2]]+t[begin[2]][i]+w[end[2]]+t[end[2]][i];
	}
	else{
		int sum = 0;
		for(int i = 1; i <= n; i++) sum += w[begin[2]]+t[begin[2]];
	}
	return 0;
}
