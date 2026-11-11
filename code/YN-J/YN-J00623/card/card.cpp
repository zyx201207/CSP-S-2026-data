#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int s[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 1, j = 0; i <= a, j <= a; j++, i++) {
		cin >> s[i];
		int sum = s[j];
		if (s[i] == sum) {
			sum << 1;
		} else {
			continue;
		}
		cout << sum;
	}
	return 0;
}