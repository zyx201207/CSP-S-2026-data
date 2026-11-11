#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	int sum;
	for(int i=1;i<=2;i++)
	{
		if(b[2]+1<='C'&&b[2]>='A'||d[2]<='C'&&d[2]>='A')
	    {
		sum++;
	    }
	}
	if(a[1]==c[1]&&a[0]==c[0])
	{
		cout <<"1";
	}
	else
	{
		cout <<"0";
	}
	if(b[0]==d[0]&&b[1]==d[1])
	{
		cout <<"1";
	}
	else
	{
		cout <<"0";
	}
	if(b[0]==d[0]&&b[1]==d[1])
	{
		if(sum==2)
		{
			cout <<"1";
		}
		else if(sum==0)
		{
			cout <<"1";
		}
		else
		{
			cout <<"0";
		}
	}
	if(sum==0)
	{
		cout <<"1";
	}
	else if(b[2]+1==d[2])
	{
		cout <<"1";
	}
	else
	{
		cout <<"0";
	}	
	return 0;
}
