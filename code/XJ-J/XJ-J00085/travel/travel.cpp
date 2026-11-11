#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char h1=' ',h2=' ';
	int z1=0,z2=0,i=0;
	if(c1==c2)
	{
		cout <<1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	while(i<s1.size()-1 || i<s2.size()-1)
	{
		if('0'<=s1[i] && s1[i]<='9')
		{
			z1=z1*10+s1[i]-48;
		}
		if('0'<=s2[i] && s2[i]<='9')
		{
			z2=z2*10+s2[i]-48;
		}
		i++;
	}
	if(s1[i]=='D')
	{
		s1[i]++;
	}
	if(s2[i]=='D')
	{
		s2[i]++;
	}
	if(z1==z2)
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(('A'<=s1[i] && s1[i]<='C'&& 'A'<= s2[i] && s2[i]<='C') || ('E'<=s1[i] && s1[i]<='F'&& 'E'<=s2[i] && s2[i]<='F'))
	{
		cout << 1;
		if(s1[i]+1==s2[i] || s2[i]+1==s1[i])
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
		cout << "00";
	}
	return 0;
}
