#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b; 
int main()
{
    freopen("travel.in",r,stdin);   
    freopen("travel.out",w,stdout); 
    for(int i = 1;i <= 2;i++)
	{
		cin >> c1[i];
	}
	for(int i = 1;i <= 2;i++)
	{
		cin >> c2[i];
	}
	for(int i = 1;i <= 3;i++)
	{
		cin >> s1[i];
	}
	for(int i = 1;i <= 3;i++)
	{
		cin >> s2[i];
	}
	for(int i = 1;i <= 2;i++)
	{
		if(c1[i] == c2[i] && c1[i + 1] == c2[i + 1])
		{
			a = 1;
			cout << 1;
			continue;
		}
		else 
		{
			cout << 0 << 0 << 0 << 0;
			break;
		}
	}
	for(int i = 1;i <= 2;i++)
	{
		if(a == 1 && s1[i] == s2[i] && s1[i + 1] == s2[i + 1])
		{	
		    b = 1;
			cout << 1;
			continue;
		}
	}
	for(int i = 1;i <= 3;i++)
	{
		if(a == 1 && b == 1)
		{
			if(s1[i + 2] - '0' == s2[i + 2] - '0' + 1 || s1[i + 2] - '0' == s2[i + 2] - '0' - 1)
			{
				cout << 1;
			}
		}
	}
	return 0;
}

