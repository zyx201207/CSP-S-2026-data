#include <bits/stdc++.h>
using namespace std;
long long arr[1000000];

int main () {
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> arr[i];
	}
	cout << a + b;
	return 0;
}