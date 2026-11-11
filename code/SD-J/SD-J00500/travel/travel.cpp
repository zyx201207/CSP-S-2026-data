#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char x,y;
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c)
	{
		cout<<1;
		if(b==d)
		{
			cout<<1;
			int u=x-'0';
			int v=y-'0';
			if((u>=17&&u<=19&&v>=17&&v<=19))
			{
				cout<<1;
				if(abs(u-v)==1)cout<<1;
				else cout<<0;
			}
			else if((u>=20&&u<=22&&v>=20&&v<=22))
			{
				cout<<1;
				if(abs(u-v)==2)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else 
	{
		cout<<0<<0<<0<<0;
	}
	 
	return 0;
}
