#include <bits/stdc++.h>
using namespace std;
int a[100];

int main() {
	int b, c;
	cin >> b >> c;
	for (int i = 1; i <= 18; i++) {
		cin >> a[i];
		for (int j = 1; j <= 5; j++) {
			cin >> a[j];
		}
	}
	for (int i = 1; i <= b; i++) {
		if (b == 0) {
			cout << b;
		}
	}
	return 0;
}