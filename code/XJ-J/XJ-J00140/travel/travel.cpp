#include<bits/stdc++.h>
using namespace std;
int c1,c2,ans;
string s1,s2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0')
		{
			cout<<1;
			if(s2[2]-'A'<=2&&s1[2]-'A'<=2)
			{
				cout<<1;
				if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(s1[2]-'A'>=3&&s2[2]-'A'>=3)
			{
				cout<<1;
				if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
