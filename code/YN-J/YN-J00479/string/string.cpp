#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N], sum;
char c[N];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r])
			sum++;
		l++;
		r--;
	}
	cout << sum << endl;
	return 0;
}