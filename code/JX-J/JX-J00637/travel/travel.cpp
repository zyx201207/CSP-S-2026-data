#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,b;
string c,d;
cin>>a>>c>>b>>d;
if(a!=b)
{
	cout<<"0000";
	return 0;
}
else
{
	cout<<'1';
	if(c[0]!=d[0]||c[1]!=d[1])
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<'1';
		if((c[2]<'D'&&d[2]>'C')||(c[2]>'C'&&d[2]<'D'))
		{
			cout<<"00";
			return 0;
		}
		else
		{
			cout<<'1';
			if(max(c[2],d[2])-min(c[2],d[2])!=1)
			{
				cout<<'0';
				return 0;
			}
			else
			{
				cout<<'1';
				return 0;
			}
		}

	}
}
}
