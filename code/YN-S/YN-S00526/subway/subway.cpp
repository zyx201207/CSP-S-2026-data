#include <bits/stdc++.h>
using namespace std;

long long m_n = 500001;
#define max 500002
#define d_max 20
#define n_max 555
long long t[n_max][d_max] = {max};
long long w[n_max];
long long node[500001];
int c, n, m, d, q;
int x, y;


void knowtime(int n) {
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		q = q * 2;
		for (int j = 0; j < q; j++) {
			long long n_n;
			cin >> n_n;
			cin >> t[i][n_n];
		}
	}
}


void f(int d, int x) {

	int flag[m_n];
	for (int i = 0; i < n; i++) {
		node[i] = max;
		flag[i] = 0;
	}
	node[x] = 0;
	flag[x] = 1;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (flag[x] == 1)
				continue;
			if (node[i] > t[j][i] + t[j][x]) {
				node[i] = t[j][i] + t[j][x];
			}
		}
	}
}



int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int l = 0; l < q; l++) {
		knowtime(n);
		cin >> x >> y;
		f( d, x);

		cout << node[y] + w[x] + w[y] << " ";

	}

	return 0;
}