#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<"0000";
	}
	else
	{
		if(s2[0]==s4[0]&&s2[1]==s4[1])
		{
			if((s2[2]-'A'<3&&s4[2]-'A'<3)||(s2[2]-'A'>2&&s4[2]-'A'>2))
			{
				if(abs(s2[2]-s4[2])==1||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D'))
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
		else
		{
			cout<<"1000";
		}
	}
}
