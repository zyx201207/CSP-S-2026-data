#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,x,y,p,q;
int n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	x=b[0]+b[1];
	y=d[0]+d[1];
	p=b[2];
	q=d[2];
	int flag=0,flag1=0,flag2=0;
	if(a==c)
	{
		cout << 1;
		flag=1;
	}
	else
	{
		cout << 0;
	}
	if(flag==1&&x==y)
	{
		cout << 1;
		flag1=1;
	}
	else
	{
		cout << 0;
	}
	if(flag1==1)
	{
		if((p>="A"&&p<="C"&&q>="A"&&q<="C")||((p=="D"||p=="F")&&(q=="D"||q=="F")))
		{	
			cout << 1;
			flag2=1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	if(flag2==1)
	{
		n=int(b[2]);
		m=int(d[2]);
	}
	else if(flag2==0)
	{
		cout << 0;
		return 0;
	}
	if(flag1==1&&flag2==1)
	{
		if(n-m==1||m-n==1)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}
