#include<bits/stdc++.h>
using namespace std;
int n,m,c,d;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	c=(a[0]-'0')*10+(a[1]-'0');
	d=(b[0]-'0')*10+(b[1]-'0');
	if(c==d)
	{
		cout<<1;
		if(a[2]<='C' && a[2]>='A' && b[2]<='C' && b[2]>='A' || a[2]<='D' && a[2]>='F' && b[2]<='D' && b[2]>='F' )
		{
			cout<<1;
			
			if(a[2]-b[2]==1  || b[2]-a[2]==1)
			{
				
				if(a[2]!='D' && b[2]!='C'  ||  a[2]!='C' && b[2]!='D')
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
				cout<<0;
			}
		}
		else
		{
			cout<<0;
			cout<<0;
		}
	}
	else 
	{
		cout<<0;
		cout<<0;
		cout<<0;
	
	}
	
} 
