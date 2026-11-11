#include <bits/stdc++.h>
using namespace std;
long long d[1000000];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int a, s;
	cin >> a >> s;
	for (int i = 1; i <= a; i++) {

		cin >> d[i];
	}
	for (int i = 1; i <= s; i++) {
		cout << d[i] << " ";
	}
	return 0;
}