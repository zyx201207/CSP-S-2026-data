#include<bits/stdc++.h>
using namespace std;
bool f, f1;
const int N = 5e5 + 10, M = 1e5 + 10;
long long a[N],t[N],w[N], k[510], x[M], y[M], ans, c, n, m, d, q;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>> c >> n >> m >> d >> q;
	if (c == 0) {
		
	}
	for (int i = 1; i <= m; i++){
		cin>> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin>> k[i];
		if (k[i] > 2) f = 1;
		for (int j = 1; j <= 2 * k[i]; j++){
			cin>> a[i] >> t[i];
		}
	}
	for (int i = 1; i <= m; i++){
		cin>> x[i] >> y[i];
	}
	for (int i = 1; i <= q; i++){
		if (!f){
			ans += w[x[i]];
			ans += w[y[i]];	
			for (int j = 1; j <= n; j++){
				ans += t[j] * 2;
			}
		}
		if (12 <= c && c <= 19){
			ans += t[1] * 2;
			for (int j = 1; j <= n; j++){
				ans += t[j] * 2;
			}
		}
	}
	return 0;
} 
