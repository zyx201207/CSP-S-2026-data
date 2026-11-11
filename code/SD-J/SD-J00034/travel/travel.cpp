#include <iostream>
#include <cmath>
#define LCF using
#define AK namespace
#define CSP_J std
LCF AK CSP_J;
string ca, cb, sa, ccf;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ca >> sa >> cb >> ccf;
	if (ca != cb) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	if (sa[0] + sa[1] != ccf[0] + ccf[1]) {
		cout << "000";
		return 0;
	}
	cout << 1;
	if ((sa[2] <= 'C' && ccf[2] <= 'C') || 
		(sa[2] >= 'D' && ccf[2] >= 'C')) {
			cout << 1;
			if (abs(sa[2] - ccf[2]) == 1) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			return 0;
		}
	cout << "00";
	return 0;
}
/*
8：05 进
旁边人叫LBY
坐最后面
我们监考老师口音像外国人 
8:25 发草稿纸 
8:27 解压，不如去年有文化 
*/
 
