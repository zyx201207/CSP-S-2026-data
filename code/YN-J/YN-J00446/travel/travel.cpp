//¿Ó√˙ø≠  2026.10.31 csp-j
//¬√”Œ£®travel£©
#include <bits/stdc++.h>
using namespace std;
int a, c;
string b, d;
bool d1, d2, d3, d4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c)
		d1 = 1;
	if (d1) {
		if (b[0] == d[0] && b[1] == d[1])
			d2 = 1;
		if (d2) {
			if ((d[2] == 'A' || d[2] == 'B' || d[2] == 'C') && (b[2] == 'A' || b[2] == 'B' || b[2] == 'C'))
				d3 = 1;
			else if ((d[2] == 'D' || d[2] == 'F') && (b[2] == 'D' || b[2] == 'F'))
				d3 = 1;
			if (d3)
				if (d[2] == char(b[2] - 1) || d[2] == char(b[2] + 1))
					d4 = 1;
		}
	}
	if (d1)
		cout << 1;
	else
		cout << 0;
	if (d2)
		cout << 1;
	else
		cout << 0;
	if (d3)
		cout << 1;
	else
		cout << 0;
	if (d4)
		cout << 1;
	else
		cout << 0;
	cout << endl;
	return 0;
}