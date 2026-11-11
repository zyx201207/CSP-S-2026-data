#include <bits/stdc++.h>
using namespace std;
bool f(char s) {
	return 'A' <= s && 'C' >= s;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << 1;
			if (f(b[2]) == f(d[2])) {
				cout << 1;
			} else cout << 0;
			cout << (abs(b[2] - d[2]) == 1);
		} else cout << 0;
	} else cout << 0;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
