#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll N = 1e5+7;
int a, b;
string x, y, n, m, z, c; 
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> x >> b >> y;
	n = x.substr(0, 2);
	m = y.substr(0, 2);
	z = x.substr(2, 3);
	c = y.substr(2, 3);	
	if (a == b)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (n == m and a == b)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if ((a == b) and (n == m) and 
	   (((z == "A" or z == "B" or z == "C") and (c == "A" or c == "B" or c == "C")) or
	   ((z == "F" or z == "D") and (c == "F" or c == "D"))    ))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (n == m and ((z == "A" and c == "B") or (z == "B" and c == "C") or (z == "D" and c == "F") or (c == "A" and z == "B") or (c == "B" and z == "C") or (c == "D" and z == "F")))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0; 
}
