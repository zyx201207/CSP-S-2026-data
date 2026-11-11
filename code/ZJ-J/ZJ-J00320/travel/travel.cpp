#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(e=='F'||e=='D') e+=5;
	if(f=='F'||f=='D') f+=5;
	if(a==c)
	{
		cout<<1;
		if(b==d)
		{
			cout<<1;
			if(abs(e-f)<=2)
			{
				cout<<1;
				if(abs(e-f)==1||(e=='I'&&f=='K')||(e=='K'&&f=='I'))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
					return 0;
				}
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