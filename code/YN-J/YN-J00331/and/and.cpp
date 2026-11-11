#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N], c[N], d;

int main() {
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int i = 1; i <= a; i++) {
			if (a % 2 == 0) {
				b[i] = 0;
				b[i++];
			} else {
				b[i] = 1;
				b[i++];
			}
		}
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
			for (int j = 1; j <= a; j++) {
				if (a % 2 == 0) {
					c[j] = 0;
					c[i++];
				} else {
					c[j] = 1;
					c[j++];
				}
			}
		}
		d = c[j] & b[i];
	}
	cout << d;
	return 0;
}