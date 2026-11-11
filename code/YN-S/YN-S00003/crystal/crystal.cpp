#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500005;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, f = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		int d = m;
		int x = 0;
		for (int j = 0; j < i; j++) {
			int c = a[i] - a[j];
			if (c <= d) {
				a[j] = a[j] + c;
				d -= c;
				x++;
			} else {
				continue;
			}
		}
		f = max(x, f);
	}
	cout << f + 1;
	return 0;
}