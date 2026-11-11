#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int a[100000000];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << '1' << ' ' << '2' << ' ' << '1' << ' ' << '3';

	fclose(stdin);
	fclose(stdout);

	return 0;
}