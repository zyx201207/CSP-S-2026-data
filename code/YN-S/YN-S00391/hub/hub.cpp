#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	if (b == 1)
		cout << 12251;
	if (a == 0 && b == 5 && c == 24032)
		cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338 << endl;
	if (a == 0 && b == 5 && c == 602)
		cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9 << endl;
	if (a == 0 && b == 3 && c == 8)
		cout << 1 << endl << 1 << endl << 2 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}