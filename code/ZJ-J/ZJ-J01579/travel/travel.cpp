#include<bits/stdc++.h>
using namespace std;
string c,s,n,m;
int a,b,d,e;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>n>>s>>m;
	a=1;
	for(int i=0;i<=1;i++)
	{
		if(c[i]!=s[i])
		{
			a=0;
			break;
		}
	}
	b=0;
	d=0;
	e=0;
	if(n[1]==m[1]&&a==1)
	{
		b=1;
		if(n[2]=='A'||n[2]=='B'||n[2]=='C')
		{
			if(m[2]=='A'||m[2]=='B'||m[2]=='C')
			{
				d=1;
				if(abs(m[2]-n[2])==1)
				{
					e=1;
				}
			}
		}
		else if(n[2]=='D'||n[2]=='F')
		{
			if(m[2]=='D'||m[2]=='F')
			{
				d=1;
				if(abs(m[2]-n[2])==1)
				{
					e=1;
				}
			}
		}
	}
	cout<<a<<b<<d<<e; 
	return 0;
}


