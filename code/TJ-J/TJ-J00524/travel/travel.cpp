#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a = 0,b = 0,c = 0,d = 0;
	if(c1 == c2)
	{
		a = 1;
		return true;
	}
	else
	{
		return false;
	}
	if(s1 == s2)
	{
		b = 1;
		return true;
	}
	else
	{
		b = 0;
		return false;
	}
	for(int i = 1;i <= s2;i++)
	{
		if(s1 == s2)
		{
			c = 1;
			return true;
		}
		else 
		{
			return false;
		}
	}
	d = 1;
	cout << 1000 * a + 100 * b + 10 * c + d;
	return 0;
}
