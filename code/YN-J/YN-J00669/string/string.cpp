#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int f, c, a;
	char b;
	cin >> f >> c;
	for (int i = 0; i < f; i++) {
		cin >> a >> b;
	}
	cout << c - a *int(b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}