#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e; 
int n,m;
bool f=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		e[0]='1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++)
	{
		if(b[i]!=d[i])
		{
			f=1;
			break;
		}
	}
	if(f)
	{
		e[1]='0';
	}
	else
	{
		e[1]='1';
	}
	if(((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&!f)
	{
		e[2]='1';
	}
	else
	{
		e[2]='0';
	}
	n=(int)d[2];
	m=(int)(b[2]);
	if(abs(n-m)==1&&!f&&(d[2]!='c'&&b[2]!='D')&&(b[2]!='c'&&d[2]!='D'))
	{
		e[3]='1';
	}
	else
	{
		e[3]='0';
	}
	for(int i=0;i<=3;i++)
	{
		cout<<e[i];
	}
	return 0;
}

