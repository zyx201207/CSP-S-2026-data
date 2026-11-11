#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1[2],c2[2];
	char s1[3],s2[3];
	for (int i=1;i<=2;i++)
	{
		cout<<c1[i];
	}
	for (int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	for (int i=1;i<=2;i++)
	{
		cout<<c2[i];
	}
	for (int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if (c1[2]==c2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if (s1[2]==s2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if (s1[3]=='A' && s2[3]=='B')
	{
		cout<<"1";
		cout<<"1";
	}
	else
	{
		if (s1[3]=='B' && s2[3]=='A')
		{
			cout<<"1";
			cout<<"1";
		}
		else
		{
			if (s1[3]=='B' && s2[3]=='C')
			{
				cout<<"1";
				cout<<"1";
			}
			else
			{
				if (s1[3]=='C' && s2[3]=='D')
				{
					cout<<"0";
					cout<<"1";
				}
				else 
				{
					if (s1[3]=='D' && s2[3]=='C')
					{
						cout<<"0";
						cout<<"1";
					}
					else
					{
						if (s1[3]=='D' && s2[3]=='E')
						{
							cout<<"1";
							cout<<"1";
						}
						else
						{
							if (s1[3]=='E' && s2[3]=='D')
							{
								cout<<"1";
								cout<<"1";
							}
							else
							{
								cout<<"0";
								cout<<"0";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
