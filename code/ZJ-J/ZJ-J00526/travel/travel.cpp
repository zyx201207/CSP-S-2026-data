#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		cout<<1;
		if(s1[0]==s2[0]&&s2[1]==s1[1])
		{
			cout<<1;
			int t=s1[2]-'A'+1,u=s2[2]-'A'+1;
			if((t<4&&u<4)||(t>3&&u>3))
			{
				cout<<1;
				if(abs(t-u)==1) cout<<1;
				else 
				{
					cout<<0;
					return 0;
				}
			}
			else 
			{
				cout<<"00";
				return 0;
			}
		}
		else 
		{
			cout<<"000";
			return 0;
		}
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}