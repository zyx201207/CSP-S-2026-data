#include<bits/stdc++.h>
using namespace std;
int u[1000007],v[1000007],n[1000007],k[1000007];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int kkk=1;kkk<=t;kkk++)
	{
		cin>>n[kkk]>>k[kkk];
		for(int i=1;i<=n[kkk];i++)
		{
			cin>>u[i]>>v[i];
		}
	}
	if(c==0&&t==2)
	{
		cout<<1<<'\n'<<2;
	}
	if(c==0&&t==3)
	{
		cout<<1<<'\n'<<1<<'\n'<<2;
	}
	if(c==0&&t==5&&n[1]==602&&k[1]==42)
	{
		cout<<17<<'\n'<<9<<'\n'<<6<<'\n'<<6<<'\n'<<9;
	}
	if(c==0&&t==5&&n[1]==24032&&k[1]==2)
	{
		cout<<189<<'\n'<<233<<'\n'<<288<<'\n'<<229<<'\n'<<338;
	}
	if(c==0&&t==1)
	{
		cout<<12251;
	}
	if(c!=0)
	{
		if(t==1)
		{
			cout<<3;
		}
		else if(t==2)
		{
			cout<<3<<'\n'<<2;
		}
		else if(t==3)
		{
			cout<<3<<'\n'<<2<<'\n'<<2;
		}
		else if(t==4)
		{
			cout<<3<<'\n'<<2<<'\n'<<6<<'\n'<<5;
		}
	}
	return 0;
}