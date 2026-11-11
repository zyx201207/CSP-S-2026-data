#include <iostream>
#include <string>
using namespace std;

const int N = 2e5 + 10;
int a[N], n;
char c[N];
long long ans = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];

	int l = 1, r = n, ls = a[1], rs = a[n];
	char lc = c[1], rc = c[n];

	while (l < r) {
		if (ls >= rs) {
			if (lc != rc)
				ans += rs;
			ls -= rs;
			rs = 0;
		} else {
			if (lc != rc)
				ans += ls;
			rs -= ls;
			ls = 0;
		}
		if (ls == 0) {
			l++;
			ls = a[l];
			lc = c[l];
		}
		if (rs == 0) {
			r--;
			rs = a[r];
			rc = c[r];
		}
	}
	cout << ans;
	return 0;
}
