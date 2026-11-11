#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
			int f=b[2]-d[2];
			if(f<0)
			{
				f=-f;
				b[2]=d[2];
			}
			
			if(f==1&&b[2]=='D')
			{
				cout<<"00";
			}
			else if(f==1)
			{
				cout<<"11";
			}
			else if(f==2&&b[2]=='C')
			{
				cout<<"10";
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
	else
	{
		cout<<"0000";
	}
}
