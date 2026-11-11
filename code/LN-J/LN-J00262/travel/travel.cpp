#include <bits/stdc++.h>
using namespace std;
struct T
{
	int id;
	char a[3];
};
T x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> x.id;
	for(int i=0;i<3;i++)
	{
		cin >> x.a[i];
	}
	cin >> y.id;
	for(int i=0;i<3;i++)
	{
		cin >> y.a[i];
	}
	if(x.id==y.id)
	{
		cout<<"1";
		if(x.a[1]==y.a[1])
		{
			cout<<"1";
			if(((x.a[2]=='A') || (x.a[2]=='B') || (x.a[2]=='C')) && ((y.a[2]=='A') || (y.a[2]=='B') || (y.a[2]=='C')))
			{
				cout<<"1";
				if((x.a[2]=='A' && y.a[2]=='B') || ((x.a[2]=='B') && (y.a[2]=='A' || y.a[2]=='C')) || (x.a[2]=='C' && y.a[2]=='B'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if((x.a[2]=='D' || x.a[2]=='F') && (y.a[3]=='D' || y.a[2]=='F'))
			{
				cout<<"11";
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
