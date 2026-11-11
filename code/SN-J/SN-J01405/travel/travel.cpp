#include <bits/stdc++.h>
using namespace std;
char a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[5],c2[5],s1[5],s2[5];
	
	for(int i=1;i<=2;i++)
	{
		cin>>c1[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>c2[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>s1[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1[1]==s1[1]&&c1[2]==s1[2])
	{
		if(c2[1]==s2[1]&&c2[2]==s2[2])
		{
			if((c2[3]-'0'<=19 && s2[3]-'0'<=19)||(c2[3]-'0'>=20 && s2[3]-'0'>=20))
			{
				if((c2[3]-'0')-(s2[3]-'0')==1 || (s2[3]-'0')-(c2[3]-'0')==1)
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
} 
