#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string as,bs;
	cin>>a>>as>>b>>bs;
	if(a==b)
	{
		cout<<1;
		if(as[0]==bs[0]&&as[1]==bs[1])
		{
			cout<<1;
			if((as[2]+bs[2]=='D'+'F')||(as[2]+bs[2]=='A'+'B')||(as[2]+bs[2]=='B'+'C'))
			{
				cout<<11;
			}
			else if(as[2]+bs[2]=='A'+'C')
			{
				cout<<10;
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
