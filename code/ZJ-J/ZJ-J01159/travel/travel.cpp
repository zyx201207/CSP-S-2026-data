#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int d[1010];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	d['A'] = 0;
	d['B'] = 0;
	d['C'] = 0;
	d['D'] = 1;
	d['F'] = 1;
	cin >> c1 >> s1 >> c2 >> s2;
	string l1 = s1.substr(0,2);
	string l2 = s2.substr(0,2);
	char p1 = s1[2];
	char p2 = s2[2];
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && l1 == l2) cout << 1;
	else cout << 0;
	if(c1 == c2 && l1 == l2 && d[p1] == d[p2]) cout << 1;
	else cout << 0;
	if(c1 == c2 && l1 == l2 && d[p1] == d[p2] && ((p1 != 'A' || p2 != 'C') && (p1 != 'C' || p2 != 'A'))) cout << 1;
	else cout << 0;
	return 0;
}
