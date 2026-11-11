#include <bits/stdc++.h>
using namespace std;
int n;
long long a;
string s;
string c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cin >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	long long cnt = s.size() - 1;
	long long sum = 0;
	for (int i = 0; i <= cnt; i++) {
		if (s[i] != s[cnt]) {
			sum++;
		}
		cnt--;
	}
	cout << sum;
	return 0;
}