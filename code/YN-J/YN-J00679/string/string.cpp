#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, o = 0;

struct node {
	int cnt;
	char c ;
} f[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		if (f[o].c == y) {
			f[o].cnt += x;
		} else {
			o++;
			f[o].c = y;
			f[o].cnt = x;
		}
	}
	int ans = 0, k = 1;
	if (o == 1) {
		cout << 0;
		return 0;

	} else {

		while (k < o) {
			if (f[k].cnt == f[o].cnt && f[k].c == f[o].c) {
				k++, o--;
			} else {
				if (f[k].cnt == f[o].cnt) {
					ans += f[o].cnt;
					o--;
					k++;
				} else if (f[k].c == f[o].c) {
					if (f[k].cnt > f[o].cnt) { //1
						f[k].cnt -= f[o].cnt;
//						cout << "a";
						o--;
					} else { //2
						f[o].cnt -= f[k].cnt;
//						cout << "b";
						k++;
					}
				} else {
					if (f[o].cnt > f[k].cnt) { //3
						ans += f[k].cnt;
						f[o].cnt -= f[k].cnt;
						k++;
//						cout << "c";
					} else {
						ans += f[o].cnt;
						f[k].cnt -= f[o].cnt;
						o--;
//						cout << "d";
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
