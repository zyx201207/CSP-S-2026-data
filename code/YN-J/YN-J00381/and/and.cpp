#include <bits/stdc++.h>
using namespace std;

struct stu {
	int n;
	char a[35];
	int wei;
} m[200005];
int cnt = 0, mxcnt = 0, micnt = 40, shu, ashu, maxans = 0, ans = 0;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> shu >> ashu;

	for (int i = 1; i <= shu; i++) {

		cin >> m[i].n;
	}//输入

	for (int i = 1; i <= shu; i++) {

		while (m[i].n > 0) {
			cnt++;
			m[i].a[cnt] = '0' + (m[i].n % 2);
			m[i].n /= 2;
		}

		m[i].wei = cnt;
		cnt = 0;
	}//二进制转换

	int bei = 1;

	for (int i = 1; i <= shu - 1; i++) {

		for (int j = i + 1; j <= shu; j++) {

			if (m[i].wei == m[j].wei) {
				for (int k = 1; k <= m[i].wei; k++) {

					if (m[i].a[k] == m[j].a[k] && m[i].a[k] == '1')
						ans += bei;
					bei *= 2;
				}
			} else {
				micnt = min(m[i].wei, m[j].wei);

				for (int k = 1; k <= micnt; k++) {

					if (m[i].a[k] == m[j].a[k] && m[i].a[k] == '1')
						ans += bei;
					bei *= 2;
				}
			}

			maxans = max(maxans, ans);
			bei = 1;
			ans = 0;
		}
	}//位运算

	cout << maxans;
	return 0;
}