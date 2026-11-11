#include <bits/stdc++.h>
using namespace std;
int a[210000], b[210000];

int main() {
	freopen("and.in"."r".in);
	freopen("and.out"."w".out);
	int n, m;
	cin >> n >> m;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] == a[i] || a[i + 1];
		if (b[i] > maxx)
			b[i] = maxx;
	}
	cout << maxx;
	return 0;
}