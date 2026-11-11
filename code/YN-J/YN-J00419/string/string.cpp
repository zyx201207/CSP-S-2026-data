#include <bits/stdc++.h>
using namespace std;
int n;
string s;
long long a;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (long long j = 1; j <= a; j++)
			s += c;
	}
	//cout << s.size() << endl << s;
	n = s.size();
	long long ccfgay = 0;
	for (int i = 0; i <= (n + 1) / 2 - 1; i++) {
		ccfgay += (s[i] != s[n - i - 1]);
		//cout << i << " "  << n - i - 1 << endl;
	}
	cout << ccfgay;
	return 0;
}