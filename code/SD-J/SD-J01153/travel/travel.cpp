#include<bits/stdc++.h>
using namespace std;
string s,t,ss,tt;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s>>t>>ss>>tt;
	if(s==ss)
	{
		if(t[0]==tt[0]&&t[1]==tt[1])
		{
			if(t[2]>'C'&&tt[2]>'C')
			{
				cout<<"1111"; 
			}
			else if(t[2]<'D'&&tt[2]<'D')
			{
				if((t[2]=='A'&&tt[2]=='C')||(tt[2]=='A'&&t[2]=='C'))
				{
					cout<<"1110";
				}
				else
				{
					cout<<"1111";
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
	else
	{
		cout<<"0000";
	}
	return 0;
} 
