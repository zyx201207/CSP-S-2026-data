#include <bits/stdc++.h>
using namespace std;
long long  m, n, a[200005];

int main() {
	freopon("and.in","r",stdin);
	freopon("and.out","w",stdout);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	cout << a[n - m + 1 ];
	return 0;
}