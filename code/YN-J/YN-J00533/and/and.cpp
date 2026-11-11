#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a, b, c[200005];
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> c[i];
	}
	int d = 0, e[200005];
	for (int i = 0; i < a; i++) {
		for (int j = i + 1; i < a; i++) {
			e[d] = c[i] & c[j];
		}
		d++;
	}
	cout << c[a - 1] << " ";
	fclose(stdin);
	fclose(stdout);
}