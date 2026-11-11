#include <iostream>
using namespace std;
int shi1[100000];

struct ixian {
	int bian;
	int ishu;
	int izhan[100000];
	int ishi[100000];
};
ixian a[502];
int num[100000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int zhan, xian, shu, ji, li = 0;
	int ce;
	cin >> ce >> xian >> zhan >> shu >> ji;
	for (int i = 0; i < zhan; i++) {
		cin >> shi1[i];
	}
	for (int i = 0; i < xian; i++) {
		a[i].bian = i + 1;
		cin >> a[i].ishu;
		for (int j = 0; j < a[i].ishu; j++) {
			cin >> a[i].izhan[j] >> a[i].ishi[j];
		}
	}
	int p, k;
	for (int i = 0; i < ji; i++) {
		cin >> p >> k;
		for (int j = 0; j < xian; j++) {
			for (int f = 0; f < a[j].ishu; f++) {
				if (a[j].izhan[f] == k) {
					if (a[j].bian == 1) {
						num[li] = a[j].ishi[0] + a[j].ishi[k - 1]
						          + shi1[0] + shi1[k - 1];
						li++;
					} else {
						for (int h = 0; h < a[j].ishu; h++) {
							for (int kk = 0; kk < a[0].ishu; kk++) {
								if (a[j].izhan[h] == a[0].izhan[kk]) {
									num[li] = a[0].ishi[p - i] + shi1[0] +
									          +a[0].ishi[kk - 1] + a[j].ishi[h - 1]
									          + shi1[k - 1] + a[j].ishi[k - 1];
									li++;
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < ji; i++) {
		cout << num[i] << endl;
	}
	return 0;
}