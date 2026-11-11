#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
long long n, m, c, d, q, dis[M], k, x, y, u, v, w, b[M], sum[M],sum1[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("wubway.out", "w", stdout);
	cin >> c >> n >> m>> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k; 
		for (int j = 1; j <= k; j++) {
			cin >> v >> w;
			if(j != v) 	sum1[v] += w;;
		}
	}
	for (int i = 1; i <= m ;i++){
		sum[i] = sum[i - 1] + b[i];
	}
	while(q--) {
		cin >> x >> y;
		if(x >y) swap(x,y);
		cout << sum1[y] - sum1[x - 1] + sum[y] - sum[x - 1]<< endl;
	}
	return 0;
}
