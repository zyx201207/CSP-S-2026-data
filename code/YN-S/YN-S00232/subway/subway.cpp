#include <bits/stdc++.h>
using namespace std;

long long c, n;	//地铁线路数；
long long m;	//地铁站数；
long long d;	//最多经过数；
long long q;	//出行计划数；
long long w[500005];	//走到站厅时间；
long long k[500005];	//经过地铁站数；
long long a[505];		//经过的第j个站台；
long long t[500005];	//走到i线路站台时间；
long long x[100005], y[100005];	//起点，终点编号；
long long sumt[100005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++ ) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
		}
	}
	for (int j = 1; j <= q; j++) {
		cin >> x[j] >> y[j];
	}
	cout << sumt;
	return 0;
}