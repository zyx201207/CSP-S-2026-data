#include <bits/stdc++.h>
using namespace std;
char c1[15],s1[15],c2[15],s2[15],flag=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
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
	for(int i=1;i<=2;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<0<<0<<0<<0;
			return 0;
		}	
	}
	cout<<1;
	for(int i=1;i<=2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	if(s1[3]<='C'&&s2[3]>='D')
	{
		cout<<0<<0;
		return 0;
	}
	if(s2[3]<='C'&&s1[3]>='D')
	{
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if((s1[3]-'0')-(s2[3]-'0')==1||(s1[3]-'0')-(s2[3]-'0')==-1)
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}