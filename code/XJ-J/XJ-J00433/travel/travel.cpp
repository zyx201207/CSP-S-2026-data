#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
string a,b,c,d;
int x,y,n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	x=a[0]*10+a[1];
	y=b[0]*10+b[1];
	n=c[0]*10+c[1];
	m=d[0]*10+d[1];
	if(x!=n)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		if(y!=m)
		{
			cout<<"000";
		}
		else
		{
			cout<<1;
			if((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C'))
			{
				cout<<1;
				if(abs((int)(b[2]-d[2]))==1)
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
				cout<<"00";
			}
		}
	}
	return 0;
}