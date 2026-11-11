#include<bits/stdc++.h>
using namespace std;
string b,d,b1="",d1="",a,c;
int b2,d2;
int main()
{
	freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	a="",b="",c="",d="";
	cin>>a>>b>>c>>d;

	b2=b[2]-'A'+1;
	d2=d[2]-'A'+1;
	b1+=b[0];
	b1+=b[1];
	d1+=d[0];
	d1+=d[1];
	if(a==c)
	{
		cout<<1;
		if(b1==d1)
		{
			cout<<1;
			if(b2+d2!=7)
			{
				cout<<1;
				if(abs(b2-d2)<=1)
				{
					cout<<1;
				}
				else cout<<0;
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}