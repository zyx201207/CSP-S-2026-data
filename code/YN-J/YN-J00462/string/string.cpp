#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;

struct node {
	int ni;
	char ac;
} a[200005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int mid = 0;

	for (int i = 1; i <= n; i++) {

		cin >> a[i].ni >> a[i].ac;
		mid += a[i].ni;
	}

	int yu, cnt = 0;

	for (int i = 1, j = n; i < j; i++, j--) {

		if (a[i].ac == a[j].ac) {
			yu = abs(a[i].ni - a[j].ni);

			if (a[i].ni < a[j].ni) {
				a[i].ni = 0;
				a[j].ni = yu;
				j++;
			} else {
				a[j].ni = 0;
				a[i].ni = yu;
				i--;
			}
		} else {
			cnt += min(a[i].ni, a[j].ni);
			yu = abs(a[i].ni - a[j].ni);

			if (a[i].ni < a[j].ni) {
				a[i].ni = 0;
				a[j].ni = yu;
				j++;
			} else {
				a[j].ni = 0;
				a[i].ni = yu;
				i--;
			}
		}
	}

	cout << cnt;

	return 0;
}