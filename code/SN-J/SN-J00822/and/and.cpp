// 张睿航 SN-J00822 西安市第六中学 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll zhn, zhm;
ll zha[100005];
ll zhans = 0;
ll zhdp[2005][2005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> zhn >> zhm;
	for(int i = 1; i <= zhn; i ++) {
		cin >> zha[i];
		zhdp[i][0] = zha[i];
	}
	sort(zha + 1, zha + zhn + 1);
	for(int j = 1; j <= zhm; j ++) {
		for(int i = 1; i <= zhn; i ++) {
			for(int k = 1; k < i; k ++) {
				zhdp[i][j] = max(zhdp[i][j], zhdp[k][j - 1] & zha[i]);
			}
		}
	}
	for(int i = 1; i <= zhn; i ++) zhans = max(zhans, zhdp[i][zhm]);
	cout << zhans;
	return 0;
}
