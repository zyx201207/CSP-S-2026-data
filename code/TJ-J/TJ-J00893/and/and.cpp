#include <bits/stdc++.h>
using namespace std;
int p[200005] = {0};
int a[200005] = {0};
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int max = -1;
	int n, m, ad = 1;
	cin >> n >> m;
	cin >> a[0];
	int sol = m - 1, l = m - 1;

	for (int i = 1;i < n;i++) {
		cin >> a[i];
	}

	for (int i = 0;i < m;i++) {
		p[i] = a[i];
	}
	int v = 0;
	int e = n;
	for (int i = 0;1;i++) {
		if (p[0] == a[n - m] && p[m - 1] == a[n - 1]) {
			break;
		}
		if (sol + v + 1 >= e) {
			sol--;
			e--;
			l--;
			v = 0;
		}
		int sum = p[0];
		for (int i = 1;i < m;i++) {
			sum &= p[i];
		}
		if (sum > max) {
			max = sum;
		}
		
		p[l] = a[sol + v + 1];
		v++;
	}
	cout << max << endl;
	return 0;
} 
