#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;

struct zd {
	int num;
	char word;
};
zd zf[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		zf[i].word = c;
		zf[i].num = a;
	}
	int i = 1, j = n, pos = 0;
	while (i <= j && i <= n && j >= 1) {
		if (zf[i].word != zf[j].word) {
			if (zf[i].num >= zf[j].num) {
				ans += zf[j].num;
				zf[i].num -= zf[j].num;
				zf[j].num = 0;
			} else {
				ans += zf[i].num;
				zf[j].num -= zf[i].num;
				zf[i].num = 0;
			}
		} else {
			if (zf[i].num >= zf[j].num) {
				zf[i].num -= zf[j].num;
				zf[j].num = 0;
			} else {
				zf[j].num -= zf[i].num;
				zf[i].num = 0;
			}
		}
		if (zf[i].num == 0) {
			i++;
		}
		if (zf[j].num == 0) {
			j--;
		}
	}
	cout << ans;
	return 0;
}