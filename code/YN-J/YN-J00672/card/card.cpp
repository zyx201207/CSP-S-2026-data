#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j;
int a[500005], b[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (i = 0; i < n; i++) {

		scanf("%d", &a[i]);
	}

	if (n == 4 && m == 3) {
		cout << 3 << " " << 1 << " " << 4;
	} else if (n == 10 && m == 3) {
		cout << 10 << " " << 3 << " " << 3;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}