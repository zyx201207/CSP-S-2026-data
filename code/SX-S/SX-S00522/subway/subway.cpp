#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, p;
	int maxn = 500100;
	int k[m + 10];
	int stop[500100];
	int qi[p + 10], zhong[p + 10];
	vector<int> rout[maxn];
	vector<int> time[maxn];
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin << stop[i];
	}
	for (int i = 1; i <= n; i = i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> rout[i][j] >> timr[i][j];
		}
	}
	for (int i = 0; i < p; i++) {
		cin >> qi[i] >> zhong[i];









	}

}