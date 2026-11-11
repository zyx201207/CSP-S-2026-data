#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,c,ct,st;
	cin>>c>>s>>ct>>st;
	if(c==ct)
	{
		cout<<1;
		int k,b;
		k=(s[0]-'0')*10+(s[1]-'0');
		b=(st[0]-'0')*10+(st[1]-'0');
		if(k==b)
		{
			cout<<1;
			if(s[2]>='A'&&s[2]<='C'&&st[2]>='A'&&st[2]<='C')
			{
				cout<<1;
				if(s[2]=='A'&&st[2]=='C'||s[2]=='C'&&st[2]=='A')
				{
					cout<<0;
				} 
				else
					cout<<1;
				
			}
			else if(s[2]>='D'&&s[2]<='F'&&st[2]>='D'&&st[2]<='F')
			{
				cout<<11;
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
