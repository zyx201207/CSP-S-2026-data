#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rc,Rp;
	string Xc,Xp;
	bool ok=true,t=true,b=true,y=true;
	cin>>Rc>>Rp>>Xc>>Xp;
	for(int i=0;i<2;i++)
	{
		if(Rc[i]!=Xc[i])
		{
			ok=false;
		}
	}
	if(ok)
	{
		cout<<"1";
	}
	else
	{
		cout<<0;
	}
	for(int i=0;i<2;i++)
	{
		if(Rp[i]!=Xp[i]||!ok)
		{
			t=false;
		}
	}
	if(t)
	{
	cout<<1;
    }
    else
    {
    	cout<<0;
	}
	int R=(int)Rp[2];
	int X=(int)Xp[2];
	if(R>67&&X<=67||!ok||!t||R<=67&&X>67)
	{
		b=false;
	}
	if(b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(!ok||!t||!b||abs(R-X)!=1)
	{
		y=false;
	}
	if(y)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
