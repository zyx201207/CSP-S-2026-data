#include<bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,x,y;
	cin>>c>>s>>x>>y;
	int f=0,t=0,u=0,r=0;
	if(c==x)
	{
		cout<<1;
		f+=s[0];
		f+=s[1];
		t+=y[0];
		t+=y[1];
		u=s[2];
		r=y[2];
		if(f==t)
		{
			cout<<1;
			if(u>='A'&&u<='C'&&r>='A'&&r<='C'||u>='D'&&u<='F'&&r>='D'&&r<='F')
			{
				cout<<1;
				if(u+1==r||u-1==r)
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
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
