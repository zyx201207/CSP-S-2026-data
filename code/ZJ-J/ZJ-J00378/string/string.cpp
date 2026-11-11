#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int al[200010];
int ar[200010];
char cl[200010];
char cr[200010];
int lenl, lenr;
long long s[200010];
long long dp[2010][2010];
char c[200010];
string x;
string y;
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
    }

	char prec = ' ';
	int cnta = 0;
	int rstcnt = 0;
	int rsti = 0;
	for (int i = 1; i <= n; ++i) {
		if (c[i] == prec) {
			if (s[i] > s[n] / 2) {
				al[cnta] += (s[n] / 2) - s[i - 1];
				rstcnt = s[i] - ((s[n] + 1) / 2);
				if (rstcnt == 0) {
					rstcnt = a[i + 1];
					rsti = i + 1;
				} else {
					rsti = i;
				}
				lenl = cnta;
				break;
			} else {
				al[cnta] += a[i];
			}
		} else {
			if (s[i] > s[n] / 2) {
				++cnta;
				al[cnta] += (s[n] / 2) - s[i - 1];
				cl[cnta] = c[i];
				prec = c[i];
				rstcnt = s[i] - ((s[n] + 1) / 2);
				if (rstcnt == 0) {
					rstcnt = a[i + 1];
					rsti = i + 1;
				} else {
					rsti = i;
				}
				lenl = cnta;
				break;
			} else {
				++cnta;
				al[cnta] += a[i];
				cl[cnta] = c[i];
				prec = c[i];
			}
			
		}
	}
	prec = ' ';
	cnta = 0;
	for (int i = n; i >= rsti; --i) {
		if (c[i] == prec) {
			if (i == rsti) {
				ar[cnta] += rstcnt;
			} else {
				ar[cnta] += a[i];
			}
		} else {
			if (i == rsti) {
				++cnta;
				ar[cnta] += rstcnt;
				cr[cnta] = c[i];
				prec = c[i];
			} else {
				++cnta;
				ar[cnta] += a[i];
				cr[cnta] = c[i];
				prec = c[i];
			}
		}
	}
	lenr = cnta;
	for (int i = 1; i <= lenl; ++i) {
		for (int j = 1; j <= al[i]; ++j) {
			x += cl[i];
		}
	}
	cout << endl;
	for (int i = 1; i <= lenr; ++i) {
		for (int j = 1; j <= ar[i]; ++j) {
			y += cr[i];
		}
	}
	cout << endl;

	for (int i = 0; i < s[n] / 2; ++i) {
		for (int j = 0; j < s[n] / 2; ++j) {
			if (x[i] == y[j]) {
				dp[i][j] = max (dp[i][j], dp[i - 1][j - 1] + 1);
			} else {
				dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << s[n] / 2 - dp[s[n] / 2 - 1][s[n] / 2 - 1] << endl;
	fclose (stdin);
	fclose (stdout);
	return 0;
} 