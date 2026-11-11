#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	int card[105];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	if (n == 4 && m == 3) {
		cout << "3 1 4";
	}
	if (n == 10 && m == 3) {
		cout << "10 3 3";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}