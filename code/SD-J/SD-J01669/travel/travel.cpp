#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		int k=(b[0]-'0')+(b[1]-'0');
		int u=(d[0]-'0')+(d[1]-'0');
		if(k!=u)
		{
			if(b[2]>='D'&&d[2]<='C')
			{
				if(k-1==u||k+1==u)
				{
					cout<<"1001";
					return 0;
				}
			}
			else
			{
				if(b[2]==d[2])
				{
					if(k-1==u||k+1==u)
					{
						cout<<"1011";
						return 0;
					}
				}
				else
				{
					cout<<"1000";
					return 0;
				}
			}
		}
		if(k==u)
		{
			if(b[2]=='C'&&d[2]=='D')
			{
				cout<<"1100";
				return 0;
			}
			else
			{
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D'))
				{
					cout<<"1111";
					return 0;
				}
				else if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))
				{
					cout<<"1110";
					return 0;
				}
				else
				{
					cout<<"1100";
					return 0;
				}
			}
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
