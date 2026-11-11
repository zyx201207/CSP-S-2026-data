#include <bits/stdc++.h>
using namespace std;
int daan[1000000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int zhonglei, paishu;
	cin >> paishu >> zhonglei;
	int chuxian[zhonglei + 5], paidui[paishu + 5], biaozhunpaidui[paishu + 5];
	for (int xianshuru = 1; xianshuru <= paishu; xianshuru++) {
		cin >> paidui[xianshuru];
		biaozhunpaidui[xianshuru] = paidui[xianshuru];
	}
	for (int youxici = 1; youxici <= paishu; youxici++) {
		for (int bencicanyu = youxici; bencicanyu <= paishu; bencicanyu++) {
			chuxian[bencicanyu] = 1;
			for (int canyuzhiqian = youxici; canyuzhiqian < bencicanyu; canyuzhiqian++) {
				if (paidui[bencicanyu] == paidui[canyuzhiqian]) {
					for (int qinglingde = canyuzhiqian; qinglingde < bencicanyu; qinglingde++) {
						paidui[qinglingde] = 0;
						chuxian[qinglingde] = 0;
					}
				}
			}
			for (int tongji = 1; tongji <= zhonglei; tongji++) {
				if (chuxian[tongji] == 1) {
					daan[tongji] += 1;
				}
			}
			for (int geshihua = youxici; geshihua <= paishu; geshihua++) {
				paidui[geshihua] = biaozhunpaidui[geshihua];
			}
		}
	}
	for (int shuchu = 1; shuchu <= zhonglei; shuchu++) {
		cout << daan[shuchu] << " ";
	}
	return 0;
}