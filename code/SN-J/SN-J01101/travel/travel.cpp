#include <bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int x,y;
    bool f = 0,t = 0,d = 0,c = 0;
    cin >> x >> a >> y >> b;
    if (x == y)
    {
    	cout << 1;
    	f = 1;
	}
	if (f == 0)
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (f == 1 && a[0] == b[0] && a[1] == b[1])
	{
		cout << 1;
		t = 1;
	}
	if (t == 0)
	{
		cout << 0;
	}
	if (t == 1)
	{
		if (a[2] >= 'A' && a[2] <= 'C')
		{
			if (b[2] >= 'A' && b[2] <= 'C')
			{
				cout << 1;
				d = 1;
			}
		}
		else if (a[2] >= 'D' && a[2] <= 'F')
		{
			if (b[2] >= 'A' && b[2] <= 'C')
			{
				cout << 1;
				d = 1;
			}
		}
	}
	if (d == 0)
	{
		cout << 0;
	}
	if (d == 1 && (a[2] - b[2] == 1 || a[2] - b[2] == -1))
	{
		cout << 1;
		c = 1;
	}
	if (c == 0)
	{
		cout << 0;
	}
	return 0;
}
