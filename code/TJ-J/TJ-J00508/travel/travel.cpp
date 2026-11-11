#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2;
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	bool a = 0;
	if(c_1 == c_2)
	{
		cout << 1;
		a = 1;
	}
	else
	{
		cout << 0;	
	}
	
	bool b = 0;
	if(s_1[0] == s_2[0]&&s_1[1] == s_2[1] && a)
	{
		cout << 1;
		b = 1;
	}
	else
	{
		cout << 0;
	}
	
	int flag1 = 0,flag2 = 0;
	if(s_1[2] == 'A' || s_1[2] == 'B' || s_1[2] == 'C' && a)
	{
		flag1 = 0;
	}
	else
	{
		flag1 = 1;
	}
	if(s_2[2] == 'A' || s_2[2] == 'B' || s_2[2] == 'C' && a)
	{
		flag2 = 0;
	}
	else
	{
		flag2 = 1;
	}
	
	if(flag1 == flag2 && a && b)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	
	if(a && b && flag1 == flag2)
	{
		if(flag1 == 1)
		{
			cout << 1;
		}
		else
		{
			if(abs(s_1[2] - s_2[2]) == 1)
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
	return 0;
 } 
