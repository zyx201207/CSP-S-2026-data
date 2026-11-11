#include <bits/stdc++.h>
using namespace std;

int n;
int a, sum = 0, summ = 0;
char b;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int j = 0; j < a; j++)
			s += b;
		sum += a;
	}
	for (int i = 0; i < ceil(sum / 2); i++) {
		if (s[i] != s[sum - i - 1])
			summ++;
	}
	cout << summ;
	return 0;
}