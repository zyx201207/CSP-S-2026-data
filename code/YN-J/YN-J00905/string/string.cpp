#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct hw {
	int gs;
	char c;
} a[N];
int n;
long long cnt = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].gs >> a[i].c;
	}
	int l = 1, r = n;
	while (l != r) {
		if (a[l].c != a[r].c) {
			if (a[l].gs > a[r].gs) {
				cnt += a[r].gs;
				a[l].gs -= a[r].gs;
				r--;
			} else if (a[r].gs > a[l].gs) {
				cnt += a[l].gs;
				a[r].gs -= a[l].gs;
				l++;
			} else if (a[r].gs == a[l].gs) {
				cnt += a[l].gs;
				a[r].gs = 0;
				a[l].gs = 0;
				l++;
				r--;
			}
		} else {
			if (a[l].gs > a[r].gs) {
				a[l].gs -= a[r].gs;
				r--;
			} else if (a[l].gs < a[r].gs) {
				a[r].gs -= a[l].gs;
				l++;
			} else if (a[l].gs == a[r].gs) {
				l++;
				r--;
			}
		}
	}
	cout << cnt;
	return 0;
}