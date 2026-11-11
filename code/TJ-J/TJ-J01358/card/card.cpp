#include <bits/stdc++.h>
using namespace std;
int a[500005], d[500005]; // 下标为n系，值为m系
int nmd = 0, wzd[300005], aptm[300005]; // 下标为m系，值为n系
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i];
	}
	for (int t = 1; t <= n; t ++) {
		for (int i = t; i <= n; i ++) { //i、t为n系 
			nmd ++;
			bool ycz = wzd[a[i]];
			if (ycz) {
				for (int j = wzd[a[i]] + 1; j <= nmd; j ++) { // j为m系
					wzd[d[j]] = 0;
					d[j] = 0;
				}
				nmd = wzd[a[i]];
				wzd[a[i]] = 0;
			}
			else {
				d[nmd] = a[i];
				wzd[a[i]] = nmd;
			}
		}
		for (int i = 1; i <= nmd; i ++) {
			//cout << d[i] << ' ';
			d[i] = 0;
		}
		for (int i = 1; i <= m; i ++) {
			aptm[i] += bool(wzd[i]);
			wzd[i] = 0;
		}
		nmd = 0;
	}
	//cout << endl;
	for (int i = 1; i <= m; i ++) {
		cout << aptm[i] << ' ';
	}
}
