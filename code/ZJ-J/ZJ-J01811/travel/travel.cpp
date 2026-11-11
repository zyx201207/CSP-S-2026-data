#include<bits/stdc++.h>
#define ll long long
using namespace std;
string x,xx,y,yy;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>xx>>y>>yy;
	ll tx=(x[0]-'0')+(x[1]-'0')*10;
	ll ty=(y[0]-'0')+(y[1]-'0')*10;
	if(tx==ty)
	{
		cout<<1;
		tx=(xx[0]-'0')*10+(xx[1]-'0');
		ty=(yy[0]-'0')*10+(yy[1]-'0');
		if(tx==ty)
		{
			cout<<1;			
			char cx=xx[2],cy=yy[2];
			if((cx-'A'<=2&&cy-'A'<=2)||(cx-'A'>2&&cy-'A'>2))
			{
				cout<<1;
				if((cx=='A'&&cy=='B')||(cy=='A'&&cx=='B')||(cx=='C'&&cy=='B')||(cy=='C'&&cx=='B')||(cx=='D'&&cy=='F')||(cy=='D'&&cx=='F'))cout<<"1\n";
				else cout<<"0\n";				
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}