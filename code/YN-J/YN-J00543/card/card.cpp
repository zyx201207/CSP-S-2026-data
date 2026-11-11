#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n;
	long long a[500005] = {0};
	long long m;
	cin >> n >> m;
	int x = 1, y = 1, z = 1;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	if (a[1] == 1) {
		x++;

	} else {
		if (a[1] == 2) {
			y++;
		} else {
			z++;
		}
	}

	for (int i = 2; i <= n; i++) {

		for (int y = i; y <= n; y++) {

			if (a[y] == 1) {
				x++;
			} else {
				if (a[y] == 2) {
					y++;
				} else {
					z++;
				}
			}
		}
	}

	cout << x << " " << y << " " << z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}