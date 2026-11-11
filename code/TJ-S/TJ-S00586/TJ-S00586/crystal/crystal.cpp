#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in" , "r", stdin );
	freopen("crystal.out", "w", stdout);
	
	long long int n,   m;
	cin        >> n >> m;
	long long int a[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[i] == a[i - 1]) a[i] = -1;
	}
	sort(a, a + n);
	
	int l = 0, maxx = 1;
	for (int r = 1; r < n; r++) {
		if (a[r] == -1) continue;
		m -= ((a[r] - a[r - 1]) * (r - l));
		while (m < 0) {
			m += a[r] - a[l];
			l++;
		}
		if (r - l > maxx) maxx = r - l;
	}
	cout << maxx + 1;
	
	fclose(stdin );
	fclose(stdout);
	
	return 0;
}
