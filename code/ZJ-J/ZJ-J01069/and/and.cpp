#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010], ans;
int MOD, D, K, F, T, P, L, S, sum[40];
bool b[200010][40];

bool cmp(long long l, long long r) {
	return l > r;
}

long long read() {
	char ch = getchar();
	long long num = 0;
	bool p = 1;
	if (isdigit(ch)) {
		num = ch - '0';
	} else {
		p = -1;
	}
	while (true) {
		ch = getchar();
		if (!isdigit(ch)) {
			return num * p;
		} else {
			num = num * 10 + ch - '0';
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	sort(a +  1, a + n + 1, cmp);
	for (int i = 1; i <= n; i ++) {
		MOD = 1, K = 1, F = 1;
		while (a[i] >= MOD) {
			MOD *= 2;
			F ++;
		}
		while (a[i] != 0) {
			if (a[i] >= MOD) {
				b[i][32 - F + K] = true;
				sum[32 - F + K] ++;
				a[i] -= MOD;
			}
			MOD /= 2;
			K ++;	
		}
	}
/*	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= 32; j ++) {
			cout << b[i][j] << ((j % 8 == 0) ? " " : "");
		}
		cout << '\n';
	}
	for (int j = 1; j <= 32; j ++) {
		cout << sum[j] << " ";
	}
	cout << "\n----------------------------------------\n\n";
*/
	S = n, D = n;
	for (int i = 1;i <= n; i ++) {
		b[i][0] = 1;
	}
	for (int i = 1; i <= 32; i ++) {
		P = 0, L = 0;
		for (int j = 1; j <= S; j ++) {
			P += b[j][i] * b[j][0];
		}
//		cout << '\n';
		if (P < m) {
//			cout << i << "Too less!  only: " << P << '\n';
			continue;
		} else {
//			cout << i << " full!  have: " << P << '\n';
			ans += (long long)pow(2, 32 - i);
//			cout << "	ans add " << (long long)pow(2, 32 - i) << '\n';
			for (int j = 1; j <= n; j ++) {
				if (b[j][i] == 0) {
					b[j][0] = 0;
//					cout << "		ban" << j << '\n';
				}
			}
		}
		for (int j = S; j >= 1; j --) {
			if (b[j][i - 1] == 1) {
				L += b[j][0];
				if (L == 1) {
					D = j;
				}
			}
		}
		if (L >= m) {
//			cout << L << "up to:" << D << '\n';
			S = D;
			for (int j = S + 1; j <= n; j ++) {
				b[j][0] = 0;
//				cout << "		ban" << j << '\n';
			}
		}
	}
	cout << ans;
	// 4 2 3 15 12 12
	// 5 3 31 3 7 15 1
	return 0;
}