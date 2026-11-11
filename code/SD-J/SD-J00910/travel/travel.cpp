#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,n,m;
	char s1,s2;
	cin>>a>>b>>s1>>c>>d>>s2;
	if(s1=='A'||s1=='B'||s1=='C')
	n=1;
	else
	n=2;
	if(s2=='A'||s2=='B'||s2=='C')
	m=1;
	else
	m=2;
	if(a==c)
	{
		cout<<1;
		if(b==d)
		{
			cout<<1;
			if(n==m)
			{
				cout<<1;
				int x=s1-'0';
				int y=s2-'0';
				if(x==y+1||x==y-1)
				{
					cout<<1;
				}
				else
				cout<<0;
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}
