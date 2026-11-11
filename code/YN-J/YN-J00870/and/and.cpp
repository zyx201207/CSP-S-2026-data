#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	int a[20000], ans[20000], c[20000];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = a[i + 1] % a[i];
		sort(a + n, a + n + 1);
	}
	for (int i = 1; i <= n; i++) {
		cout << a[n];
		break;
	}
	return 0;
}