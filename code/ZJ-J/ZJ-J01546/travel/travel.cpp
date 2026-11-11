#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int a2=1000,a3=1100,a4=1110,a5=1111;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a.size()==c.size())
	{
		int f=0,m=b.size();
		for(int i=0;i<a.size();i++)
		{
			if(a[i]!=c[i])
			{
				for(int i=1;i<=4;i++)cout<<0;
				return 0;
			}
		}
		if(b.size()==d.size())
		{
			for(int i=0;i<m;i++)
			{
				if(b[i]>='0'&&b[i]<='9'&&d[i]>='0'&&d[i]<='9')
				{
					if(b[i]!=d[i])
					{
						cout<<a2;
						return 0; 
					}
				}
				else break;
			}
		}
		char x=b[m-1],y=d[m-1];
		if(x>='A'&&x<='C'&&y>='A'&&y<='C'||x=='D'&&x=='E'&&y=='D'&&y=='E')
		{
			if(x+1==y||x-1==y)
			{
				cout<<a5;
				return 0;
			}
			else
			{
				cout<<a4;
				return 0; 
			}
		}
		else
		{
			cout<<a3;
			return 0;
		}
	}
	else for(int i=1;i<=4;i++)cout<<0;
	return 0;
}
