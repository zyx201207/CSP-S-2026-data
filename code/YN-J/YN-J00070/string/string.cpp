#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 90;

struct  node {
	int l;
	char x;
} a[N];
int n;
int sum = 0 ;
int minn = INT_MAX;
bool flag = 1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].x;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].l == 1) {
			continue;
		} else {
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << n / 2;
		return 0;
	}
	if (n == 1) {
		cout << "0";
	}
	if (n == 2) {
		if (a[1].x == a[2].x ) {
			cout << "0";
			return 0;
		} else {
			cout << min(a[1].l, a[2].l );
		}
	}

	return 0;
}