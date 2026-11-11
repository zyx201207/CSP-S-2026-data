#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	
	int c1,c2,n;
	cin >> c1 >> c2;
	string s1[5];
	string s2[5];
	string order1[6];
	string order2[3];
	for (int i=0;i<=2;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for (int i=0;i<=2;i++)
	{
		cin >> order1[i];
	}for (int i=0;i<=1;i++)
	{
		cin >> order2[i];
	}
	
	if (c1 == c2)
	{
		n = 1000;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1])
	{
		n = 1100;
	}
	
	if (s1[2] == order1[] && s2[2] == order1[])
	{
		n = 1110;
	}
	if (s1[2] == order2[] && s2[2] == order2[])
	{
		n = 1110;
	}
	
	if (s1[2] + 1 = s2[2] || s1[2] - 1 = s2[2])
	{
		n = 1111;
	}
	cout << n;
	
	return 0;
}
