#include <bits/stdc++.h>
using namespace std;
string s1, c1, s2, c2;
int a1, a2;
int b1, b2;
char o1, o2;
bool a, b, c, d;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a1 = int(c1[0] - '0') * 10 + int(c1[1] - '0');
	a2 = int(c2[0] - '0') * 10 + int(c2[1] - '0');
	o1 = s1[2], o2 = s2[2];
	b1 = int(s1[0] - '0') * 10 + int(s1[1] - '0');
	b2 = int(s2[0] - '0') * 10 + int(s2[1] - '0');
	if (a1 == a2) {
		a = 1;
		if (b1 == b2) {
			b = 1;
			if (int(o1 - 'A') < 3 && int(o2 - 'a') < 3  ||  int(o1 - 'D') < 2 && int(o1 - 'D') < 2) {
				c = 1;
				if (abs( int(o1) - int(o2) ) == 1)
					d = 1;
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}