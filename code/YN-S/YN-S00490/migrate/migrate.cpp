#include <bits/stdc++.h>
using namespace std;
int n, d;
int l[1000];

int s(int a, int s) {
	int c = 0;
	for (int i = 0; i < a; i++) {
		int u = i;
		int q = 0;
		for (int j = 0; j < a; j++) {
			int v = j;
			if (j - v > 0 && j - v < d) {
				q++;
			}
		}
		if (q == 2)
			c++;
		else
			continue;
	}
	return c;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	cout << s(n, d)
	     fclose(stdin);
	fclose(stdout);
	return 0;
}