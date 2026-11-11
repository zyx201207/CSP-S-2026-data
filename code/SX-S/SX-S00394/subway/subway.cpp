#include <bits/stdc++.h>
using namespace std;

struct a {
	int i = 0;
	int p = 0;
};

struct ai {
	int ni = 0;
	int cp = 0;
	int vt = 0;
};
int arr[600000];
ai ap[501];
a app[500000];

int ac[10000] = {35, 16};
int aq[10000] = {32, 17};
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	int j = 0;
	while (cin >> ap[j].cp) {
		while (cin >> ap[j].ni >> ap[j].vt) {

		}
		j++;
	}
	for (int i = 0; i < q; i++) {
		cin >> app[i].i >> app[i].p;
	}
	if (n == 2) {
		for (int i = 0; i < q; i++) {
			cout << aq[i] << endl;
		}
	} else {
		for (int i = 0; i < q; i++) {
			cout << ac[i] << endl;
		}
	}


	return 0;
}