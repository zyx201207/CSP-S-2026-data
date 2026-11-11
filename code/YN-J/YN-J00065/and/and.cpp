#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int id;
	int num;
};
int n;
int m;
int x[200010];
int a[200010][35];
int len[200010];
int y;
int ret = 2147483647;
int flag;
node b[200010];

bool cmp(node x, node y) {
	return x.num > y.num;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i += 1) {
		cin >> x[i];
		y = x[i];
		while (y != 0) {
			len[i] += 1;
			a[i][len[i]] = y % 2;
			y /= 2;
		}
	}
	for (int i = 1; i <= n; i += 1) {
		reverse(a[i] + 1, a[i] + 31);
	}
	for (int i = 1; i <= 31; i += 1) {
		flag = 0;
		for (int j = 1; j <= n; j += 1) {
			if (a[j][i] == 1) {
				flag += 1;
			}
		}
		if (flag == m) {
			for (int j = 1; j <= n; j += 1) {
				if (a[j][i] == 1) {
					ret = ret & x[j];
				}
			}
			break;
		} else if (flag > m) {
			for (int j = 1; j <= n; j += 1) {
				if (a[j][i] == 1) {
					for (int k = i; k <= 31; k += 1) {
						if (a[j][k] == 0) {
							b[j].num = k - i;
							break;
						}
					}
				}
				b[j].id = j;
			}
			sort(b + 1, b + n + 1, cmp);
			for (int j = 1; j <= m; j += 1) {
				ret = ret & x[b[j].id];
			}
			break;
		}
	}
	cout << ret;
	return 0;
}