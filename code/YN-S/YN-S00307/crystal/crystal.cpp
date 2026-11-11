#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n;
long long m, x;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0;

	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		x = m;
		for (int k = i; k <= n; k++) {
			if (x >= a[i] - a[k]) {
				x = x - (a[i] - a[k]);
				cnt++;
			} else {
				break;
			}
		}
		sum = max(sum, cnt);
		if (n - i < sum) {
			break;
		}
	}
	cout << sum;
	return 0;
}