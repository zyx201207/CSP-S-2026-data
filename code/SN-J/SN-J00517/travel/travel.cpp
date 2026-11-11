#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r"stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2,ss1,ss2;
	cin>>s1>>s2>>ss1>>ss2;
	if(s1==ss1)
	{
		cout<<1;
		if((s2[1]==ss2[1]) && (s2[0]==ss2[0]))
		{
			cout<<1;
			if((s2[2]<='C' && ss2[2]<='C') || (s2[2]>='D' && ss2[2]>='D'))
			{
				cout<<1;
				if(s2[2]+1==ss2[2] || s2[2]-1==ss2[2])
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
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
