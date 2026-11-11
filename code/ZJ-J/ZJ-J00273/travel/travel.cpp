#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[10],s1[10],c2[10],s2[10];
	int a,b,c,d;
	for(int i=1;i<=2;i++)
	{
		cin>>c1[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>c2[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1[1]==c2[1]&&c1[2]==c2[2])
	{
		a=1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2])
	{
		b=1;
	}
	else
	{
		cout<<"1000";
		return 0;
	}
	if(s1[3]<='C'&&s2[3]<='C')
	{
		if((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='A')||(s1[3]=='C'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='C'))
		{
			cout<<"1111";
			return 0;
		}else
		{
			cout<<"1110";
			return 0;
		}
	}
	else if(s1[3]>'C'&&s2[3]>'C')
	{
		cout<<"1111";
		return 0;
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	return 0;
}