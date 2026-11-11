#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cpr,cpx;
	string czwr,czwx,par,pax;
	int pr,px,zwr,zwx;
	cin>>cpr>>czwr>>cpx>>czwx;
	pr=(cpr[0]-'0')*10+(cpr[1]-'0');
	px=(cpx[0]-'0')*10+(cpx[1]-'0');
	zwr=(czwr[0]-'0')*10+(czwr[1]-'0');
	zwx=(czwx[0]-'0')*10+(czwx[1]-'0');
	par=czwr[2];
	pax=czwx[2];
	//cout<<pr<<" "<<px<<" "<<zwr<<" "<<zwx<<" "<<par<<" "<<pax;
	if(pr==px)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(zwr==zwx)
	{
		cout<<1;
		if((int(par[0])<=67 and int(pax[0])<=67) or (int(par[0])>67 and int(pax[0])>67) )
		{
			cout<<1;
			if((par[0]-pax[0])==-1 or (par[0]-pax[0])==1)
			{
				cout<<1;	
			}
			else
			{
				cout<<"0";
			}
		}
		
		else
			cout<<"00";
	}
	else
	{
		cout<<"000";
	}
	
	
	
	return 0;
}