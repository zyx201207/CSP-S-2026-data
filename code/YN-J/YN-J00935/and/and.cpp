#include <bits/stdc++.h>
using namespace std;
long long arr[1000000];

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> arr[i];
	}
	cout << a + b << endl;
	return 0;
}