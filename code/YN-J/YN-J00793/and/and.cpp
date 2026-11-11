#include <bits/stdc++.h>
using namespace std;
int n[200005];

int main() {
	freopen("and.in", "r", "stdin");
	freopen("and.out", "w", "stdout");
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> n[i];
	}
	sort(n + 1, n + 1 + a);
	cout << n[a - b + 1];
	return 0;
}