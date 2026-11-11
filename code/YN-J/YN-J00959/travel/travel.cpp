#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, c;
	char e, f, g, h;
	cin >> a;
	for (int i = 1; i <= 3; i++) {
		char b;
		cin >> b;
		if (b == '0' || b == '1' || b == '2' || b == '3' || b == '4' || b == '5' || b == '6' || b == '7' || b == '8'
		        || b == '9')
			e += b;
		if (b == 'A' || b == 'B' || b == 'C' || b == 'D' || b == 'E' )
			g += b;
	}
	cin >> c;
	for (int i = 1; i <= 3; i++) {
		char d;
		cin >> d;
		if (d == '0' || d == '1' || d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8'
		        || d == '9')
			f += d;
		if (d == 'A' || d == 'B' || d == 'C' || d == 'D' || d == 'E')
			h += d;
	}
	int ans = 0;
	if (a == c)
		ans += 1;
	if (e == f)
		ans += 1;
	if (g == 'A' && h == 'B' || g == 'A' && h == 'C' || g == 'B' && h == 'C' || g == 'D' && h == 'E' || g == 'B'
	        && h == 'A' || g == 'C' && h == 'A' || g == 'C' && h == 'B' || g == 'E' && h == 'D')
		ans += 1;
	if (g == 'A' && h == 'B' || g == 'B' && h == 'C' || g == 'D' && h == 'E' || g == 'B' && h == 'A' | g == 'C' && h == 'B'
	        || g == 'E' && h == 'D')
		ans += 1;
	if (ans == 0)
		cout << "0000";
	if (ans == 1)
		cout << 1000;
	if (ans == 2)
		cout << 1100;
	if (ans == 3)
		cout << 1110;
	if (ans == 4)
		cout << 1111;
	return 0;
}