#include <iostream>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100000001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int b[100000001];
	int count = 0;
	for (int o = 0; o < n; o++) {
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
			for (int j = i; j > 0; j--) {
				if (b[i] == b[j]) {
					for (int z = j; z < i; z++) {
						b[z] = 0;
					}
					b[i] = b[j];
				}
			}
			for (int z = 0; z < n; z++) {
				a[z] = b[z];
			}
			for (int y = 0; y < n; y++) {
				if (a[y] == n) {
					count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}