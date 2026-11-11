#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		if(s1[0,1]!=s2[0,1])
		{
			cout<<"1000";
		}
		else
		{
			if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'))
			{
				if(s1[2]+1==s2[2] || s1[2]-1==s2[2])
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
	}
	return 0;
}
