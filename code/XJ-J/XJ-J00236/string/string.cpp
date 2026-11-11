#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	string s,k;
	int a,ai;
	cin >> a ;
	for(int i=1;i<=a;i++)
	{
		cin >> ai;
		cin >> k;
		for (int i=1;i<=ai;i++)
		{
			s+=k;
		}
	}
	int c=s.length(),num=0,num1=0,num2=0; 
	
	for (int i=0;i<=c/2;i++)
	{
		if (s[i]==s[c-1-i])
		{
		}
		else
		{
			num++;
		}
	}
	
	for (int i=0;i<=c/2;i++)
	{
		if (s[i]==s[c-i])
		{
		}
		else
		{
			num1++;
		}
	}
	
	for (int i=0;i<=c/2;i++)
	{
		if (s[i]==s[c+1-i])
		{
		}
		else
		{
			num2++;
		}
	}
	cout << min(min(num1,num2),num);
	return 0;
}
