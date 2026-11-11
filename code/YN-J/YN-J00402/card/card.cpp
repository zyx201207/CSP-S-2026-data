#include <bits/stdc++.h>
using namespace std;
int a[500005];
int a1[500005];

bool b[300005] = {0};

int c[300005] = {0};

int t1[500005];
int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a1[i] = a[i];
		b[i] = 0;
		c[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (b[a[j]] == 0) {
				b[a[j]] = 1;
				t1[a[j]] = j;
			} else {
				int t = 0;
				t = j - 1;
				while (t >= t1[a[j]]) {
					a1[t] = 0;
					t--;
				}
			}
		}
		for (int j = i; j <= n; j++) {
			if (a1[j])
				c[a1[j]]++;

		}
		for (int j = 1; j <= n; j++) {
			b[j] = 0;
			t1[j] = 0;
		}
		for (int j = 1; j <= i; j++) {
			a[j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] != 0)
			cout << c[i] << " " ;
	}
	return 0;
}