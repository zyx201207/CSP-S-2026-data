#include <iostream>
#include <algorithm>
using namespace std;

struct niao {
	int dao;
	int d;
	int zuo[1000];
};
niao a[10000];
int op[10000];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int ce, n;
	cin >> ce >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].dao >> a[i].d;
		for (int j = 0; j < a[i].dao; j++) {
			cin >> a[i].zuo[j];
		}
		op[i] = a[i].dao;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].dao - 1; j++)  {
			if (a[i].zuo[j + 1] - a[i].zuo[j] > a[i].d ) {
				op[i]--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int num = 1;
		int u = op [i] - a[i].d * a[i].d;
		if (u < 0) {
			cout << 0 << endl;
		}
		if (u == 0) {
			cout << 1 << endl;
		}
		if (u > 0) {
			for (int i = 0; i < u; i++) {
				num = num * 2;
			}
			cout << num << endl;
		}
	}
	return 0;
}