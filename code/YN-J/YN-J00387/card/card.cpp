#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int tong[300010];
int card[500010];
int n, m;

void pd(int l, int r) {
	for (int i = l; i < n; i++) {
		for (int j = r; j >= i; j--) {
			if (card[i] == card[j]) {
				for (int k = 0; k < i; k++) {
					tong[card[k]]++;
				}
				for (int k = j; k < n; k++) {
					tong[card[k]]++;
				}
			}
		}
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	int l = 0;
	int r = n - 1;

	while (l != r) {
		pd(l, r);
		l++;
	}

	for (int i = 0; i < m; i++) {
		cout << tong[i + 1] << ' ';
	}



	return 0;
}