#include<bits/stdc++.h>
using namespace std;
int fun(string a,string b)
{
	int f=0;
	if(a[2]>='A'&&a[2]<='C')
	{
		if(b[2]>='A'&&b[2]<='C')
		{
			f=1;
		}
	}
	else
	{
		if(b[2]>='D'&&b[2]<='F')
		{
			f=1;
		}
	}
	if(f==0)
	{
		return 0;
	}
	else return 1;
}
int funn(string a,string b)
{
	int i=a[2]-'0',j=b[2]-'0';
	if(i==20&&j==22) return 1;
	if(abs(i-j)==1) return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&a==c) cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&fun(b,d)==1&&a==c) 
	{
		cout<<1;
	}
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&fun(b,d)==1&&funn(b,d)==1&&a==c)
	{
		cout<<1;
	}
	else cout<<0;
	 
	return 0;
} 
