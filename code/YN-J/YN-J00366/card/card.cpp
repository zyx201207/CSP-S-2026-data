#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long a[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
//	for (int i = 1; i <= n / 2; i++) {
//		for (int j = n; j >= n / 2 ; j--)
//			if (c[i] != c[j]) {
//				cout << sum / 2 << endl;
////				cout << c[i] << " " << c[j] << " " << i << " " << j << endl;
//				return 0;
//			}
//	}
//	cout << 0 << endl;
	for (int i = 1; i <= m; i++)
		cout << a[i];
	return 0;
}
