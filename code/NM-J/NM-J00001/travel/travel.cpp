#include"bits/stdc++.h"
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    bool xf,xs,xt,xe;
    cin>>a>>b>>c>>d;
    xf=true;
    for(int i=0;i<2;i++)
	{
		if(a[i]!=c[i])
		{
			xf=false;
			cout<<"0000"<<endl;
			return 0;
		}
	}
	xs=true;
	if(xf)
	{
		for(int i=0;i<2;i++)
		{
			if(b[i]!=d[i])
			{
				xs=false;
				cout<<"1000"<<endl;
				return 0;
			}
		}
	}
	xt=false;
	if(xs)
	{
		if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='A'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')
		{
			xt=true;
		}
		if(!xt)
		{
			cout<<"1100"<<endl;
		}
	}
	xe=false;
	if(xt)
	{
		if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='F'&&d[2]=='D'||b[2]=='D'&&d[2]=='F')
		{
			xe=true;
			cout<<"1111"<<endl;
		}
		if(!xe)
		{
			cout<<"1110"<<endl;
		}
	}
    return 0;
}
