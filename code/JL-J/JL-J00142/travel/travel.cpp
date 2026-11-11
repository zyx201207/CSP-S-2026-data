#include<bits/stdc++.h>
using namespace std;
string x,y,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>a>>b;
	if(x=="01"||x=="16"||a=="01"||a=="16"||x!=a)
	{
		cout<<"0000";
		cout<<'\n';
		return 0;
	}
	else
	{
		cout<<1;
	}
	if(y[0]==b[0]&&y[1]==b[1])
	{
		cout<<1;
		if((y[2]>='A'&&y[2]<='C'&&b[2]>='A'&&b[2]<='C')||(y[2]>='D'&&y[2]<='F'&&b[2]>='D'&&b[2]<='F'))
		{
			cout<<1;
			if(y[2]+1==b[2]||y[2]==b[1]+1||(y[2]=='D'&&b[2]=='F')||(y[2]=='F'&&b[2]=='D'))
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
			cout<<"00";
			cout<<'\n';	
			return 0;
		}
	}
	else
	{
		cout<<"000";
		cout<<'\n';
		return 0;
	}
	cout<<'\n';
	return 0;
}
