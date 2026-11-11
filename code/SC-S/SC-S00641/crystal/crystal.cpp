#include <iostream>
#include <algorithm>

using namespace std;
const int SZ = 5e5 + 5;

int n, l, r, maxn = 0;
long long m, sum = 0;
long long a[SZ], d[SZ]; 

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (l = r = 1; r <= n; r++) {
		d[r] = d[r - 1] + a[r];
		sum = a[r] * (r - l + 1) - (d[r] - d[l - 1]);
		while (sum > m) {
			l++; sum = a[r] * (r - l + 1) - (d[r] - d[l - 1]);
		}
		maxn = max(maxn, r - l + 1);
	}
	
	cout << maxn;
	return 0;
}
