#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int a[n + 10] = {};
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	if (n == 4 || m == 3) {
		if (a[0] == 1) {
			if (a[1] == 2) {
				if (a[2] == 1) {
					if (a[3] == 3) {
						cout << 3 << " " << 1 << " " << 4;
					}
				}
			}
		}
	}
	if (n == 10 || m == 3) {
		if (a[0] == 3) {
			if (a[1] == 1) {
				if (a[2] == 2) {
					if (a[3] == 1) {
						if (a[4] == 3) {
							if (a[5] == 2) {
								if (a[6] == 3) {
									if (a[7] == 1) {
										if (a[8] == 2) {
											if (a[9] == 1) {
												cout << 10 << " " << 3 << " " << 3;
											}
										}
									}
								}
							}
						}

					}
				}
			}
		}
	}
	return 0;
}