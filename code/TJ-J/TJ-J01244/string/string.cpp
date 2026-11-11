#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a;
	char b;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		for (int j = 1; j <= a; j++) {
			s += b;
		}
	}cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
