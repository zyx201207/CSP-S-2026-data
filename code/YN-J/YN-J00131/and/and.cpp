#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n;
	long long a[200005];
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long nb = 0;
	long long jb = a[n - 1];
	long long j = 0;
	for (long long i = n - 2; i > n - m; i--) {
		nb = 0;
		while (a[i] > 0) {
			if (jb % 2 == a[i] % 2) {
				nb += (jb % 2 ) * pow(2, j);
			}
			nb /= 2;
			a[i] /= 2;
			j++;
		}
		jb = nb;
	}
	cout << jb;



	return 0;
}