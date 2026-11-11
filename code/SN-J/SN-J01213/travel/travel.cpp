#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		int s,t;
		s=(s1[0]-'0')*10+(s1[1]-'0');
		t=(s2[0]-'0')*10+(s2[1]-'0');
		if(s==t)
		{
			cout<<1;
			char wasds,wasdt;
			wasds=s1[2],wasdt=s2[2];
			if(wasds=='F' || wasds=='E')
			{
				if(wasdt=='F' || wasdt=='E')
				{
					cout<<1<<1;
					return 0;
				}
				else
				{
					cout<<0<<0;
				}
			}	
			else
			{
				if(wasdt=='A' || wasdt=='B' || wasdt=='C')
				{
					cout<<1;
					if((wasds=='A' && wasdt=='C') || (wasds=='C' && wasdt=='A'))
					{
						cout<<0;
						return 0;
					}
					else
					{
						cout<<1;
						return 0;
					}
				}
				else
				{
					cout<<0<<0;
					return 0;
				}
			}		
		}
		else
		{
			cout<<0<<0<<0;
			return 0;
		}		
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
