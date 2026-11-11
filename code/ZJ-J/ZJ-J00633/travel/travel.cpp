#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1])
		{
			cout<<1;
			if((s1[2]=='C' and s2[2]=='D') or (s1[2]=='D' and s2[2]=='C'))
			{
				cout<<"00";
			}
			else
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==1 or (s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s2[2]=='D'))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
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