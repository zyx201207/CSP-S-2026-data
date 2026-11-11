#include<bits/stdc++.h>
using namespace std;
#define N 101
char a[N],b[N],c[N],d[N];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<3;i++)
	{
		if(a[i]!=c[i])
		{
			cout<<0<<0<<0<<0<<endl;
			return 0;
		}
	}
	if(b[1]!=d[1])
	{
		cout<<1<<0<<0<<0<<endl;
		return 0;
	}
	else
	{
		if((b[2]>='A'&&b[2]<='C'&&d[2]>='D'&&d[2]<='F')||(b[2]>='D'&&b[2]<='F'&&d[2]>='A'&&d[2]<='C'))
		{
			cout<<1<<1<<0<<0<<endl;
			return 0;
		}
		else
		{
			if(b[2]>='A'&&b[2]<='C'&&b[2]>='A'&&b[2]<='C')
			{
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B'))
				{
					cout<<1<<1<<1<<1<<endl;
					return 0;
				}
				else
				{
					cout<<1<<1<<1<<0<<endl;
					return 0;
				}
			}
			else
			{
				if((b[2]=='D'||b[2]=='F')&&(b[2]=='D'||b[2]=='F'))
				{
					cout<<1<<1<<1<<1<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
