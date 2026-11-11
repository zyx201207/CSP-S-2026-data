#include<bits/stdc++.h>
//#include<iostream>
//#include<string>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2 = "";
	bool a,b = 0;
	int x,y = 0;
	//int a[20][8] = {};
	cin >> c1 >> s1 >> c2 >> s2;
	x = (s1[0] - 48)*10;
	x += (s1[1] - 48);
	y = (s2[0] - 48)*10;
	y += (s2[1] - 48);
	if(c1 == c2)
	{
		cout << 1;
		if(s1[0] + s1[1] == s2[0] + s2[1])
		{
			cout << 1;
			if(s1[2] == 'D' || s1[2] == 'F')
			{
				a = 1;
			}
			else if(s1[2] <= 'C' && s1[2] >= 'A')
			{
				a = 0;
			}
			if(s2[2] == 'D' || s2[2] == 'F')
			{
				b = 1;
			}
			else if(s2[2] <= 'C' && s2[2] >= 'A')
			{
				b = 0;
			}
		}
		if(a == b)
		{
			cout << 1;
		}
		else
		{
			cout << 0 << 0;
		}
		if(x-y <= 1 && x-y >= -1)
		{
			if(x-y == 0)
			{
				if(s1[2] - s2[2] <= 1 && s1[2] - s2[2] >= -1 && s1[2] - s2[2] != 0)
				{
					cout << 1;
				}
				else 
				{
					cout << 0;
				}
			}
			else
			{
				if(s1[2] - s2[2] == 0)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
