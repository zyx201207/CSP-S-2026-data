#include <bits/stdc++.h>

using namespace std;

int n, m, a[10005], b[10005], res[10005];

bool t, f[5005];

int main () {
	//freopen ("and.in", "r", stdin);
	//freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			b[i] = a[i];
		}
		for (int j = i + 1; j <= n; j++) {
			t = false;
			for (int k = i; k < j; k++) {
				if (b[k] == b[j]) t = true;
				if (t) b[k] = 0;
			}
		}
		for (int j = 1; j <= m; j++) f[j] = false;
		for (int j = i; j <= n; j++) f[b[j]] = true;
		for (int j = 1; j <= m; j++) if (f[j]) res[j]++;
	}
	for (int i = 1; i <= m; i++) cout << res[i] << " ";
	//fclose (stdin);
	//fclose (stdout);
	return 0;
} 
