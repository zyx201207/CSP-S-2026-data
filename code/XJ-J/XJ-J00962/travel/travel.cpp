#include<bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",strout);
	int i,j,k,t,x,y;
	int flag=1;
	cin>>a;
	cin>>n;
	cin>>b;
	cin>>m;
	for(i=0;i<2;i++)
	{
		if(a[i]!=b[i])
		{
			flag=0;
			break;
		}
	}
	cout<<flag;
	if(flag==0)
	{
		cout<<"000";
		return 0;
	}
	flag=1;
	for(i=0;i<2;i++)
	{
		if(n[i]!=m[i])
		{
			flag=0;
			break;
		}
	}
	cout<<flag;
	if(flag==0)
	{
		cout<<"00";
		return 0;
	}flag=0;
	if(n[2]=='A'||n[2]=='B'||n[2]=='C'&&m[2]=='A'||m[2]=='B'||m[2]=='C')
	{
		flag=1;
	}
	if(n[2]=='D'&&m[2]=='F'||n[2]=='F'&&m[2]=='D')
	flag=0;
	cout<<flag;
	k=n[1]-'0';
	t=m[1]-'0';
	x=n[2];
	y=m[2];
	if(flag==1)
	if(k==t&&x+1==y||y+1==x)
	{
		cout<<'1';
		return 0;
	}
	cout<<'0';
	return 0;
}