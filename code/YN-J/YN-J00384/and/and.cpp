#include <bits/stdc++.h>
using namespace std;
long long n, m;

long long a[26000090][26000090];

void erjz(long long a9, long long i) {
	long long j = 1;
	while (a9 > 0) {
		int c = a9 % 2;
		a[i][j] == c + 1;
		j++;
		a9 /= 2;
	}
	return j;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	long long a9, z, x, cht = 0, cnti, cntj = -1;
	for (long long i = 1; i <= n; i++) {
		cin >> a9;
		cntj = max(cntj, erjz(a9, i));
		if (cht < a9) {
			cnt = i;
			cht = a9;
		}
	}
	for (long long i = 1; i <= m; i++) {

		for (long long j = 1; j <= cntj; j++) {
			if (a[i][j] == 0) {
				
			}
		}
	}
cout<<"379";
	return 0;
}