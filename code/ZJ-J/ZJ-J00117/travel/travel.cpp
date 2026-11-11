#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	bool f = false;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (f = c1 == c2);
	cout << (f &= s1[0] == s2[0] && s1[1] == s2[1]);
	cout << (f &= s1[2] >= 'D' && s2[2] >= 'D' || s1[2] <= 'C' && s2[2] <= 'C');
	cout << (f && abs(s1[2] - s2[2]) == 1); 
}
