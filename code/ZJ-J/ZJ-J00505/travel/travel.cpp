#include <bits/stdc++.h>
using namespace std;

int xa , ya , za , xb , yb , zb;
string c1 , s1 , c2 , s2;

int main () {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == '0') xa = c1[1] - '0';
	else xa = 10 + c1[1] - '0';
	if (c2[0] == '0') xb = c2[1] - '0';
	else xb = 10 + c2[1] - '0';
	if (s1[0] == '0') ya = s1[1] - '0';
	else ya = 10 + s1[1] - '0';
	if (s2[0] == '0') yb = s2[1] - '0';
	else yb = 10 + s2[1] - '0';
	if (s1[2] == 'F') s1[2] = 'E';
	if (s2[2] == 'F') s2[2] = 'E';
	za = s1[2] - 'A' + 1 , zb = s2[2] - 'A' + 1;
	if (xa == xb) cout << 1;
	else cout << 0;
	if (xa == xb&&ya == yb) cout << 1;
	else cout << 0;
	if (xa == xb&&ya == yb&&(za <= 3&&zb <= 3)||(za > 3&&zb > 3)) cout << 1;
	else cout << 0;
	if (xa == xb&&ya == yb&&abs(za - zb) == 1&&((za <= 3&&zb <= 3)||(za > 3&&zb > 3))) cout << 1;
	else cout << 0;
} 