#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int s01,s02;
char s001,s002;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	s01=s1[1]*10+s1[2];
	s02=s2[1]*10+s2[2];
	if(s01==s02&&c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	for(int i=1;i<=3;i++)
	{
		s001=s1[3];
		s002=s2[3];
	}
	if(c1==c2&&s01==s02&&s001>='A'&&s001<='C'&&s002>='A'&&s002<='C'||
	c1==c2&&s01==s01&&s001>='D'&&s001<='E'&&s002>='D'&&s002<='E')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s01+1==s02&&c1==c2||s02+1==s01&&c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}