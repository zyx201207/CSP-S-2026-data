#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("trawvel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2)
	{
		cout<<"0000";
	}
	if(c1==c2)
	{
		cout<<1;
		if(s1[1]-'0'==s2[1]-'0')
		{
			cout<<1;
			if((s1[2]-'A'<=3 && s2[2]-'A'<=3) || (s1[2]-'A'>=4 && s1[2]-'A'>=4))
			{
				cout<<1;
				if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1)
				{
					cout<<1;
				}
			}
		}
	}
}