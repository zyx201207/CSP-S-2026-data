#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	bool g=0;
	if(a==b)
	{
		g=1;
		cout<<"1";
	}
	else
	cout<<0;
	bool ok=false;
	if(x[0]==y[0] and x[1]==y[1] and g)
	{
		ok=true;
		cout<<1;
	}
	else
	cout<<0;
	if(ok)
	{
		bool f=0; 
		char k=x[2],j=y[2];
		if(k>='A' and k<='C' and j>='A' and j<='C')
		{
			cout<<1;
			f=1;
		}
		else if(k>='D' and k<='F' and j>='D' and j<='F')
		{
			cout<<1;
			f=1;
		}
		else
		cout<<0;
		if(f and abs(k-j)==1)
		cout<<1;
		else
		cout<<0;
	}
	else
	cout<<0<<0;
	return 0;
 } 
