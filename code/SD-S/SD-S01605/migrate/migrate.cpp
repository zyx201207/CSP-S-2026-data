#include <bits/stdc++.h>
#define int long long
#define inf 1e18

using namespace std;

const int N = 1010, M = 2e6 + 10;

int c, t, n, d;
int a[M];

int read(){
	int v = 0, f = 1;char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		v = v * 10 + (int)(c - '0');
		c = getchar();
	}
	return v * f;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();t = read();
	while (t -- ){
		n = read();d = read();
		for (int i = 1; i <= n; i ++ ){
			a[i] = read();
		}
		bool dt = false;
		for (int i = 3; i <= n; i ++ ){
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
				dt = true;break;
			}
		}
		if (!dt){
			int dta = a[2] - a[1];
			if (2 * dta > d) cout << "0\n";
			else{
				int cnt = d / dta;
				int tmp = cnt + cnt - 1;
				if (n - tmp < 0) cout << 0;
				else cout << n - tmp;
				cout << "\n";
			}
		}else{
			int ans = 0;
			for (int i = 1; i <= n; i ++ ){
				int y = lower_bound(a + i, a + n + 1, a[i] + d) - a - 1;
				int p = upper_bound(a + y, a + n + 1, a[y] + d) - a - 1;
				if (a[p] - a[y - 1] <= d && a[p] - a[y - 2] > d) ans ++ ;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}

