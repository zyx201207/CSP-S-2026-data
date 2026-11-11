#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1[1000],s1[1000],c2[1000],s2[1000];
	cin>>c1[1000]>>s1[1000]>>c2[1000]>>s2[1000];
	if(c1==c2)
	{
		c1[1000]='1';
		c2[1000]='1';
	}
	else
	{
		c1[1000]='0';
		c2[1000]='0';
		s1[1000]='0';
		s2[1000]='0';
	}
	if(s1+1==s2 && s2+1==s1 && s1-1==s2 && s2-1==s1 && s1==s2)
	{
		s1[1000]='1';
		s2[1000]='1';
	}
	else
	{
		s1[1000]='0';
		s2[1000]='0';
	}
	cout<<c1<<s1<<c2<<s2;
	return 0;
}
