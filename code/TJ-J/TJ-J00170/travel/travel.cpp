#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	{
		cout<<1;
		int a,b;
		a=c2[0]*10+c2[1];
		b=s2[0]*10+s2[1];
		if(a==b)
		{
			cout<<1;
			char c,d;
			c=c2[2];
			d=s2[2];
			if(c=='A'||c=='B'||c=='C')
			{
				if(d=='A'||d=='B'||d=='C')
				{
					cout<<1;
				}
				else
				{
					cout<<"00";
					return 0;
				}
			}
			else if(d=='D'||d=='F')
			{
				cout<<1;
			}
			else
			{
				cout<<"00";
				return 0;
			}
			if(d+1==c||c+1==d)
			{
				cout<<1;
			}
			else if(c=='D'&&d=='F'||c=='F'&&d=='D')
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
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
