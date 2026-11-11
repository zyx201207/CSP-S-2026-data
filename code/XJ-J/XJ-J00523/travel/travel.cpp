#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0000;
		return 0;
	}
	int p1=s1/10,p2=s2/10;
	int b1=s1%10,b2=s2%10;
	if(p1==p2)
	{
		cout<<1;
	}
	else
	{
		cout<<000;
		return 0;
	}
	if(b1=='A'&&b2=='B'||b1=='A'&&b2=='C'||b1=='B'&&b2=='A'||b1=='B'&&b2=='C'||b1=='C'&&b2=='A'||b1=='C'&&b2=='B'||b1=='D'&&b2=='F'&&b1=='F'&&b2=='D')
	{
			cout<<1;
    }
	else
	{
		cout<<00;
		return 0;
	}
	if(b1=='A'&&b2=='B'||b1=='B'&&b2=='A'||b1=='B'&&b2=='C'||b1=='C'&&b2=='B'||b1=='D'&&b2=='F'&&b1=='F'&&b2=='D')
	{
		cout<<1;
	}
	else
	{
		cout<<0;		
	}
		
	return 0;
}