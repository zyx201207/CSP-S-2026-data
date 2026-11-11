#include "bits/stdc++.h"
using namespace std;
int a[200010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	//cout << n << " " << m << endl;
	int b = 0;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
//	for (int i = 0; i < n; i ++)
//		cout << a[i] << " ";




	for (int i = 0; i < n - 1; i ++) {
		for (int j = i + 1; j < n; j ++) {
			if (a[i] & a[j] > b)
				b = a[i] & a[j];
		}
	}

	printf("%d", b);
	return 0;
}