#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
int s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> s[i];
	}
	sort(s, s + a);
	int mid = a / 2 ;
	int sum = 0, g = 0;
	for (int i = mid - 1; i >= 0; i--) {
		sum += s[mid] - s[i];
		if (sum > b) {
			break;
		}
		s[i] = s[mid];
	}
	int d = s[mid];
	for (int i = 0; i < a; i++) {
		if (s[i] == d) {
			g++;
		}
	}
	cout << g;
	return 0;
}