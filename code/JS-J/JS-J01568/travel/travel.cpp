#include <bits/stdc++.h>
using namespace std;
string rn,rcn,xn,xcn;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>rn>>rcn>>xn>>xcn;
    int rct,xct;
    rct=int(rcn[2]);
    xct=int(xcn[2]);
    if(rn==xn)
    {
		cout<<'1';
		if(rcn[0]+rcn[1]==xcn[0]+xcn[1])
		{
			cout<<'1';
			if(rct<=67&&rct>=65&&xct<=67&&xct>=65)
			{
				cout<<'1';
				if(rct-xct==1||rct-xct==-1)
				{
					cout<<'1'<<'\n';
				}
				else
				{
					cout<<'0'<<'\n';
				}
			}
			else if(rct<=69&&rct>=68&&xct<=69&&xct>=68)
			{
				cout<<'1';
				if(rct-xct==1||rct-xct==-1)
				{
					cout<<'1'<<'\n';
				}
				else
				{
					cout<<'0'<<'\n';
				}
			}
			else
			{
				cout<<"00"<<'\n';
			}
		}
		else
		{
			cout<<"000"<<'\n';
		}
	}
	else
	{
		cout<<"0000"<<'\n';
	}
	
    return 0;	
}
