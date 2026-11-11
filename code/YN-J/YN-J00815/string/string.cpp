#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

string s;
char z[200005];
int sum = 0, n, m[200005];

int main() {
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[0] >> z[0];
		for (int i = 1; i <= m[0]; i++) {
			s += z[0];
		}
	}
	for (int i = 0; i < s.size() - 1 - i; i++) {
		if (s[i] != s[s.size() - 1 - i])
			sum++;
	}
	cout << sum;

	return 0;
}