//AK CSP-J!!
#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
string s1,s2;
inline long long read()
{
	char ch=getchar();
	long long x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	a=read();
	cin>>s1;
	c=read();
	cin>>s2;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000"<<'\n';
		return 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int t,t1;
	if(s1[2]=='F'||s1[2]=='D')
	{
		t=1;
	}
	else
	{
		t=0;
	}
	if(s2[2]=='F'||s2[2]=='D')
	{
		t1=1;
	}
	else
	{
		t1=0;
	}
	if(t1==t)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(t1!=t)
	{
		cout<<0<<'\n';
	}
	else if(t1==t)
	{
		if(t1==0)
		{
			if(abs(int(s1[2])-int(s2[2]))==1)
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
			if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&s2[2]=='F'))
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	return 0;
}
