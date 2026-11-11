#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,rs,c2,xs;
	cin>>c1>>rs>>c2>>xs;
	if(c1==c2) 
	{
		cout<<1;
		string rt=rs.substr(0,2);
		string xt=xs.substr(0,2);
		if(rt==xt)
		{
			cout<<1;
			if((rs[2]=='A'&&xs[2]=='B')||(rs[2]=='A'&&xs[2]=='C')||(rs[2]=='B'&&xs[2]=='C')||(rs[2]=='B'&&xs[2]=='A')||(rs[2]=='C'&&xs[2]=='B')||(rs[2]=='C'&&xs[2]=='A')||(rs[2]=='D'&&xs[2]=='F')||(rs[2]=='F'&&xs[2]=='D'))
			{
				cout<<1;
				if((rs[2]=='A'&&xs[2]=='B')||(rs[2]=='B'&&xs[2]=='C')||(rs[2]=='B'&&xs[2]=='A')||(rs[2]=='C'&&xs[2]=='B')||(rs[2]=='D'&&xs[2]=='F')||(rs[2]=='F'&&xs[2]=='D'))
				cout<<1;
				else
				cout<<0;
			}
			else
			cout<<"00";
		}
		else
		cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
