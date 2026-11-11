#include<bits/stdc++.h>
using namespace std;
int a, b;
string x, y;
bool c[100], k[100][100];
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	c['A'] = c['B'] = c['C'] = true;
	cin >> a >> x >> b >> y;
	cout << (a == b);
	bool nearh = (a == b) && (x[0] == y[0] && x[1] == y[1]);
	cout << nearh;
	bool near = (a == b) && (nearh && (c[x[2]] == c[y[2]]));
	cout << near;
	k['A']['B'] = k['B']['A'] = true;
	k['C']['B'] = k['B']['C'] = true;
	k['D']['F'] = k['F']['D'] = true;
	cout << (near && k[x[2]][y[2]]);
	return 0;
}