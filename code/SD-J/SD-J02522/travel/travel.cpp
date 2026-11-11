#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
bool b1, b2, b3, b4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3)
		b1 = 1;
	else
		b1 = 0;
	if (b1 && (s2[0] == s4[0] && s2[1] == s4[1]))
		b2 = 1;
	else
		b2 = 0;
	if (b2 && ((s2[2] <='C' && s4[2] <= 'C') || (s2[2] >= 'D' && s4[2] >= 'D')))
		b3 = 1;
	else
		b3 = 0;
	if (b3 && abs(s2[2] - s4[2]) == 1)
		b4 = 1;
	else
		b4 = 0;
	cout << b1 << b2 << b3 << b4;
	return 0;
}
