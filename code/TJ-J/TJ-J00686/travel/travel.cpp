#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a[50] = {false},b[50];
	cin >> c1 >> s1 >> c2 >> s2;
	if(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C')
	{
		b[1] = true;
	}
	else
	{
		b[1] = false;
	}
	if(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C')
	{
		b[2] = true;
	}
	else
	{
		b[2] = false;
	}
	if(c1[0]+c1[1] == c2[0]+c2[1])
	{
		a[1] = true;
		if(s1[0]+s1[1]==s2[0]+s2[1]||s1[2]==s2[2])
		{
			a[2] = true;
			if(b[1] == b[2])
			{
				a[3] = true;
				if(s1[1] == char(s2[1]-'1')||s1[1] == char(s2[1]+'1'))
				{
					a[4] = true;
				}
			}
			
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		if(a[i] == true)
		{
			cout << '1';
		}
		else
		{
			cout << '0';
		}
	}
	return 0;
 } 
