#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	bool flag;
	int num;
} a[500005];
int b[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num;
		a[i].flag = true;
	}
	for (int i = 1; i <= n; i++) {
		int c[500005] = {0};
		for (int m = 1; m <= n; m++) {
			a[m].flag = true;
		}
		for (int j = i; j <= n; j++) {
			c[j]++;
			if (c[j] > 1) {
				for (int k = 1; k <= j; k++) {
					a[k].flag = false;
				}
			}
		}
		for (int l = i; l <= n; l++) {
			for (int h = 1; h <= m; h++) {
				if (a[l].flag && a[l] == m)
					b[m]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[m];
	}
	return 0;
}