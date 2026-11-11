#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		string a1=s1.substr(0,2);
		string a2=s2.substr(0,2);
		if (a1!=a2)
		{
			cout<<"000";
		}
		else
		{
			cout<<"1";
			if (((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
			{
				cout<<"1";
				if ((s1[2]-s2[2])==1||(s1[2]-s2[2])==-1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
	}
	return 0;
}
