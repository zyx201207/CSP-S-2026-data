#include <bits/stdc++.h>
using namespace std;

struct c {
	int m, n;
	int arr[1000];
};
c ac[100000];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < b; i++) {
		cin >> ac[i].m >> ac[i].n;
		for (int j = 0; j < ac[i].m; j++) {
			cin >> ac[i].arr[j];
		}
	}
	for (int i = 0; i < b; i++) {
		cout <<	ac[i].m % ac[i].n + 1 << endl;

	}
	return 0;
}