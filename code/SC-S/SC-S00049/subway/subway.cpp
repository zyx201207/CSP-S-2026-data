#include<bits/stdc++.h>
using namespace std;
long long u[100010], k[100010], a[100010], x[100010], y[100010];
int main(){
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> u[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= 2 * k[i]; j++){
			cin >> a[j];
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x[i] >> y[i]; 
	}
	
	return 0;
}