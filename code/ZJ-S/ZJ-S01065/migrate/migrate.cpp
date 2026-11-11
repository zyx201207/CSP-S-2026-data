#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000010];
long long k[2000010], f, ans;
long long ma[5010][5010];

long long read() {
	long long num = 0;
	char ch;
	int k = 1;
	ch = getchar();
	if (ch == '-') {
		k = -1;
	} else {
		num = ch - '0';
	}
	ch = getchar();
	while (isdigit(ch)) {
		num = num * 10 + ch - '0';
		ch = getchar();
	}
	return num * k;
}

int A() {
	d /= a[2] - a[1];
	if (d <= 1) {
		return 0;
	} else {
		return max(0ll, n - 2 * d + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(); 
	t = read();
	for (int i = 1; i <= t; i ++) {	
		n = read();
		d = read();
		for (int j = 1; j <= n; j ++) {
			a[j] = read();
		}
		cout << A() << '\n';
	}
	/*for (int i = 1; i <= t; i ++) {
		n = read();
		d = read();
		a[1] = read();
		t = 1;
		for (int j = 2; j <= n; j ++) {
			a[j] = read() - a[1];
		}
		a[1] = 0;
		//if (c == 11|| c == 12) {
			cout << A() << '\n';
			return 0;
		//} 
		for (int j = 2; j <= n; j ++) {
			if (a[j] - a[j - 1] > d) {
				t ++;
				k[t] = j - 1;
			}
		}
		int cut;
		for (int j = 2; j <= t;  j ++) {
			for (int A = 1; A <= k[j] - k[j - 1] + 1; A ++) {
				ma[A][1] = a[k[j - 1] + A - 1];
				ma[1][A] = ma[A][1];
			}
			for (int A = 2; A <= k[j] - k[j - 1] + 2; A ++) {
				for (int B = A + 1; B <= k[j] - k[j - 1] + 2; B ++) {
					if (ma[B][1] - ma[1][A] <= d) {
						ma[B + 1][A + 1] = 1;
					}
				}
			}
			for (int A = 1; A <= k[j] - k[j - 1] + 1; A ++) {
				for (int B = 1; B <= k[j] - k[j - 1] + 1; B ++) {
				}
				cout << '\n';
			}
			for (int A = 2; A <= k[j] - k[j - 1] + 2; A ++) {
				for (int B = A + 1; B <= k[j] - k[j - 1] + 2; B ++) {
					if (ma[A + 2][B] == 1 && ma[A + 2][B + 1] == 0) {
						if (a[B] <= d && a[B - 1] > d) {
							for (int C = B; C <= k[j] - k[j - 1] + 1; C ++) {
								if (a[C - 1] <= d && a[C - 2] > d) {
									ans ++;
								}
							}
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}*/
	return 0;
}

/*
0 1 6 2 -4 -3 -2 -1 3 6
*/