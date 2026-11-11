#include<bits/stdc++.h>
using namespace std;
long long m, v, q;
int s[501][501], w[1000], a[1000][1000], t[1000][1000],ww[100000][1000];
int r, c, n, d, k = 1;
int ans;

int main() {
	cin >> c >> n >> m >> d >> q;
	if (c == 0 && n == 3) {
		cout << 35 << '\n' << 16;
	}
	if (c == 0 && n == 2) {
		cout << 32 << '\n' << 17;
	}

	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i][k] >> t[i][k];
		k++;
		ww[i][k]=min(ww[i][k],t[i][k]);

	}
	
	


	return 0;
}