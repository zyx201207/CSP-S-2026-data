#include <bits/stdc++.h>
using namespace std;
int w[500010];
int ai[500010];
int at[500010];
int a1[500010];
int a2[500010];
int x[5];
int y[5];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> ai[i];
		cin >> at[i];
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a1[i];
		cin >> a2[i];
	}
	for (int i = 1; i <= 2; i++) {
		cin >> x[i] >> y[i];
	}
	cout << w[1] + at[1] + (at[2] + a2[2]) + a2[3] + w[3] << endl;
	cout << w[1] + at[1] + at[2] + w[2];
	return 0;
}