#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int x;
	string y;
}a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a.x >> a.y >> b.x >> b.y;
	if(a.x == b.x)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	
	if(a.y[0] - '0' == b.y[0] - '0' && a.y[1] - '0' == b.y[1] - '0')
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	
	if((a.y[2] - 'A' < 3 && b.y[2] - 'A' < 3) || (a.y[2] - 'A' >= 3 && b.y[2] - 'A' >= 3))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
		cout << 0;
		return 0;
	}
	
	if((a.y[2] - 'A') - (b.y[2] - 'A') == 1 || (a.y[2] - 'A') - (b.y[2] - 'A') == -1 || (a.y[2] == 'D' && b.y[2] == 'F') || (a.y[2] == 'F' && b.y[2] == 'D'))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
