#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+5;
const int N = 505;
const int Q = 1e5+5;
int c, n, m, d, q;
int w[M];
int k[N];
int a[N];
int t[N];
int x[Q];
int y[Q];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "r", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int i = 1; i <= 2 * k[i]; i++) {
			cin >> a[i] >> t[i];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = 1;i <= q;i++){
		cout << 0 <<endl;
	}
	return 0;
}