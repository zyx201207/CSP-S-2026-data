#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int k[600], c, n, m, d, q;
int a[N][600], t[N][600], w[N], x[N], y[N];
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[j][i] >> t[j][i];
		}
		for(int i = 1; i <= q; i++){
			cin >> x[i] >> y[i];
		}
		cout << t[x[i]][2] + t[y[i]][2] + w[x[i]] + w[y[i]] <<endl;
	}
    return 0;
}
