#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a, b, s1, s2;
	cin >> a >> s1 >> b >> s2;
	bool f = 1;
	if(a == b)
	{
		cout << 1;
	}
	else
	{ 
		f = 0;
		cout << 0;
	}
	int x, y;
	x = (s1[0]-'0')*10+(s1[1]-'0');
	y = (s2[0]-'0')*10+(s2[1]-'0');
	if(x == y&& f == 1)
	{
		cout <<  1;
	}
	else
	{
		f = 0;
		cout << 0;
	}

	if((s1[2] == 'A' &&(s2[2]=='D' || s2[2] == 'F'))|| f != 1)
	{
		f = 0;
		cout << 0;
	}
	else if((s1[2] == 'B' &&(s2[2]=='D' || s2[2] == 'F'))|| f != 1)
	{
		f = 0;
		cout << 0;
	}
	else if((s1[2] == 'C' &&(s2[2]=='D' || s2[2] == 'F'))|| f != 1)
	{
		f = 0;
		cout << 0;
	}
	else if((s2[2] == 'C' &&(s1[2]=='D' || s1[2] == 'F'))|| f != 1)
	{
		f = 0;
		cout << 0;
	}
	else if((s2[2] == 'A' &&(s1[2]=='D' || s1[2] == 'F'))|| f != 1)
	{
		f = 0;
		cout << 0;
	}
	else if((s2[2] == 'B' &&(s1[2]=='D' || s1[2] == 'F'))|| f != 1)
	{
		f = 0;
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	
	int r = s1[2] - 'A';
	int l = s2[2] - 'A';
	
	if(f == 1 && ((l-r) == 1||(r - l) == 1))
	{
		cout << 1;
	} 
	else
	{
		cout << 0;
	}
	

	return 0;
}










