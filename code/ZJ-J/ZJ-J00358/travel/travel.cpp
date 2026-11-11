#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","out",stdout);
	cin>>a>>c>>b>>d;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	if(c[0]!=d[0] || c[1]!=d[1] )
	{
		cout<<"1000";
		return 0;
	}
	if(c[2]>'C' && d[2]>'C')
	{
		cout<<"1111";
		return 0;
	}
	if(c[2]<'D' &&  d[2]<'D')
	{
		if(c[2]-d[2]==1  ||  d[2]-c[2]==1)
		{
			cout<<"1111";
			return 0;
		 }
		 cout<<"1110"; 
		 return 0;
	}
	cout<<"1100";
	return 0;
}
