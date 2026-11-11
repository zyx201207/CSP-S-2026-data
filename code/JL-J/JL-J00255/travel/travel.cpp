#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
int rc,xc;
string rs,xs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc!=xc)
	{
		cout<<"0000";
	}else
	{
		cout<<1;
		if(rs[0]!=xs[0] || rs[1]!=xs[1])
		{
			cout<<"000";
		}else
		{
			cout<<1;
			bool f=1;
			if(rs[2]=='A' || rs[2]=='B' || rs[2]=='C')
			{
				if(xs[2]=='D' || xs[2]=='F')
					f=0;
			}else if(rs[2]=='D' || rs[2]=='F') 
			{
				if(xs[2]=='A' || xs[2]=='B' || xs[2]=='C')
					f=0;
			}
			if(!f)
			{
				cout<<"00";
			}else
			{
				cout<<1;
				if((rs[2]=='A' && xs[2]=='B')||(rs[2]=='B' && xs[2]=='A')||(rs[2]=='B' && xs[2]=='C')||(rs[2]=='C' && xs[2]=='B')||(rs[2]=='D' && xs[2]=='F')||(rs[2]=='F' && xs[2]=='D'))
				{
					cout<<1;
				}else
					cout<<0;
			}
		}
	}
	return 0;
}
