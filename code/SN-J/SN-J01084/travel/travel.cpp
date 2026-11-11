#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rche[3],rzuo[3],xche[3],xzuo[3];
	for(int i=1;i<=3;i++)
	{
		cin>>rche[i]>>rzuo[i]>>xche[i]>>xzuo[i];
	}
	if(rche[1]==xche[1] && rche[2]==xche[2])
	{
		cout<<"1";
		if(rzuo[1]==xzuo[1] && rzuo[2]==xzuo[2])
    	{
	    	cout<<"1";
		    if((rzuo[3]=='D'&&xzuo[3]=='F')||(rzuo[3]=='F'&&xzuo[3]=='D')||(rzuo[3]=='A'&&xzuo[3]=='B')||(rzuo[3]=='A'&&xzuo[3]=='C')||(rzuo[3]=='B'&&xzuo[3]=='A')||(rzuo[3]=='B'&&xzuo[3]=='C')||(rzuo[3]=='C'&&xzuo[3]=='A')||(rzuo[3]=='C'&&xzuo[3]=='B'))
		    {
		    	cout<<"1";
		    	if((rzuo[3]=='D'&&xzuo[3]=='F')||(rzuo[3]=='F'&&xzuo[3]=='D')||(rzuo[3]=='A'&&xzuo[3]=='B')||(rzuo[3]=='B'&&xzuo[3]=='A')||(rzuo[3]=='B'&&xzuo[3]=='C')||(rzuo[3]=='C'&&xzuo[3]=='B'))
		    	{
		    		cout<<"1";
				}
				else
				{
					cout<<"0";
				}
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
	return 0;
}
