// 张睿航 SN-J00822 西安市第六中学 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int zhn;
ll zhcnt = 0;
ll zhlen = 0;
ll zha[200005];
char zhc[200005];

inline int zhfnd(ll idx) {
	int t = lower_bound(zha + 1, zha + zhn + 1, idx) - zha;
	return zhc[t];
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> zhn;
	for(int i = 1; i <= zhn; i ++) {
		cin >> zha[i] >> zhc[i];
		zhlen += zha[i];
		zha[i] += zha[i - 1];
	}
	for(int i = 1; i <= zhlen / 2; i++) {
		if(zhfnd(i) != zhfnd(zhlen - i + 1)) {
			zhcnt ++;
		}
	}
	cout << zhcnt;
	return 0;
}
