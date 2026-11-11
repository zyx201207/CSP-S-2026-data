#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
using ll = long long;
int c, n, m, d, q, k[N];
ll w[N], a[N], t[N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[j] >> t[j];
		}
	}
	for(int i = 1, x, y; i <= q; i++){
		cin >> x >> y;
	}
	return 0;
}
