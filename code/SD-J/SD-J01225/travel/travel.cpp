#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool x1 = (c1 == c2);
	bool x2 = (s1[0] == s2[0] and s1[1] == s2[1]);
	bool x3 = ((s1[2] <= 'C' and s2[2] <= 'C') or (s1[2] >= 'D' and s2[2] >= 'D'));
	cout << x1;
	cout << (x1 and x2);
	cout << (x1 and x2 and x3);
	cout << (x1 and x2 and x3 and (s1[2] + 1 == s2[2] or s1[2] - 1 == s2[2]));
	return 0;
} 
