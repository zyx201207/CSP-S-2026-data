#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a;
	cin >> n;
	char c;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			cout<<c;
		}
	}
	return 0;
}