#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl "\n"
using pii=pair<int,int>;
string c1,s1,c2,s2;
int cx(string a,string b)
{
	if(a==b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pai(string a,string b)
{
	if(a[0]==b[0]&&a[1]==b[1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ce(string a,string b)
{
	if(a[0]==b[0]&&a[1]==b[1])
	{
		if(a[2]<='C'&&b[2]<='C'||a[2]>='D'&&b[2]>='D')
		{
			return 1;	
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
int ling(string a,string b)
{
	bool f=false;
	if(!pai(a,b))
	{
		return 0;
	}
	for(int i=1;i<=5;i++)
	{
		if(a[2]==b[2]+1||a[2]==b[2]-1)
		{
			f=true;
		}
	}
	if(a[2]=='C'&&b[2]=='D')
	{
		f=false;
	}
	if(f)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fast;
	cin>>c1>>s1>>c2>>s2;
	int a=cx(c1,c2);
	int b=pai(s1,s2);
	int c=ce(s1,s2);
	int d=ling(s1,s2);
	if(a==0)
	{
		b=0;
		c=0;
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;	
}