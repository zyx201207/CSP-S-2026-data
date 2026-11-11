#include <bits/stdc++.h>
using namespace std;
int a[10010];
int b[10010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= m; i++) {
		b[i] = a[i];
	}
	int sum = 0;
	int l = 0;
	for (int i = 1; i <= m; i++) {
		int b1 = b[i];
		while (b1 != 0) {
			if (b[i] % 2 == b[i + 1] % 2 ) {
				sum += pow(2, l);
				cout << sum << " ";
				l++;
			}
			b1 /= 2;

		}
	}
	cout << endl;
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	cout << sum ;
	return 0;
}