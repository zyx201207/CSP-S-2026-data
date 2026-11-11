#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N], sum;
char c[N];
char s[N];
bool flg;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i], sum += a[i];
	for (int i = 1; i <= n / 2; i++) {
		for (int j = n; j >= n / 2 ; j--)
			if (c[i] != c[j]) {
				cout << sum / 2 << endl;
//				cout << c[i] << " " << c[j] << " " << i << " " << j << endl;
				return 0;
			}
	}
	cout << 0 << endl;
	return 0;
}
