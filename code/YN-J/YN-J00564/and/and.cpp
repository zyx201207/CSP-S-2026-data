#include <bits/stdc++.h>
using namespace std;

int main() {
	freeopen("and","r",stdin);
	freeopen("and","w",stdout);
	int  n;
	int  m;
	int mina;
	cin >> n;
	int a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= m; i--) {
		mina = min(a[i], mina);
	}
	cout << mina;
	return 0;
}
