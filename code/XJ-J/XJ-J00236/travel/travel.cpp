#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("traevl.in","r",stdin);
	freopen("traevl.out","r",stdout);
	int x,r;
	string x1,r1;
	cin >> x >> x1 >> r >> r1;
	if (x==r)
	{
		cout << 1;
	}
	else
	{
		cout << 0000;
		return 0;
	}
	
	if (x1[0]==r1[0] && x1[1]==r1[1])
	{
		cout << 1;
	}
	else
	{
		cout << 000;
		return 0;
	}
	
	if (r1[2]=='E' || r1[2]=='D')
	{
		if (x1[2]=='E' || x1[2]=='D')
		{
			cout << 1;
		}
		else
		{
			cout << 00;
			return 0;
		}
	}
	
	if (r1[2]=='A' || r1[2]=='B' || r1[2]=='C')
	{
		if (x1[2]=='A' || x1[2]=='B' || x1[2]=='C')
		{
			cout << 1;
		}
		else
		{
			cout << 00;
			return 0;
		}
	}
	
	if (r1[2]=='C' || r1[2]=='D')
	{
		cout << 1;
	}
	else if ((r1[2]=='A' && x1[2]=='B' ) || (r1[2]=='B' && x1[2]=='A' ) || (r1[2]=='B' && x1[2]=='C' ) || (r1[2]=='C' && x1[2]=='B' ) )
	{
		cout <<1;
	}
	else
	{
		cout << 0;
	}
	
	return 0;
}
