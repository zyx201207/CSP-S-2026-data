#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;

struct node {
	int a;
	char c;
} a[N];
int n;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].a >> a[i].c;
	int j = n, res = 0;
	for (int i = 1; i <= n; i++) {
		while (j > i) {
			if (a[j].c == a[i].c) {
				if (a[j].a > a[i].a) {
					a[j].a -= a[i].a;
					a[i].a = 0;
					break;
				} else if (a[j].a == a[i].a) {
					a[j].a = a[i].a = 0;
					j--;
					break;
				} else {
					a[i].a -= a[j].a;
					a[j].a = 0;
					j--;
					continue;
				}
			} else {
				if (a[j].a > a[i].a) {
					res += a[i].a;
					a[j].a -= a[i].a;
					a[i].a = 0;
					break;
				} else if (a[j].a == a[i].a) {
					res += a[i].a;
					a[j].a = a[i].a = 0;
					j--;
					break;
				} else {
					a[i].a -= a[j].a;
					res += a[j].a;
					j--;
					continue;
				}
			}
		}
	}
	cout << res;
	return 0;
}