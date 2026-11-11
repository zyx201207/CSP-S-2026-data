#include <bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2, s3, s4, s5, s6;
bool f1, f2, f3;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	f1 = (c1 == c2);
	cout << f1;
	s3 = s1.substr(0, 2);
	s4 = s2.substr(0, 2);
	f2 = (s3 == s4);
	cout << (f1 && f2);
	f3 = (((s1[2] >= 'A' && s1[2]<='C') && (s2[2] >= 'A' && s2[2]<='C')) || ((s1[2] >= 'D' && s1[2]<='F') && (s2[2] >= 'D' && s2[2]<='F')));                      
	cout << (f1 && f2 && f3);
	cout << ((f1 && f2 && f3 && (s1[2] <= 'C') && abs((int)(s1[2] - 'A') - (int)(s2[2] - 'A')) == 1) || (f1 && f2 && f3 && (s1[2] >= 'D') && abs((int)(s1[2] - 'A') - (int)(s2[2] - 'A')) == 2));
	return 0;
 } 
