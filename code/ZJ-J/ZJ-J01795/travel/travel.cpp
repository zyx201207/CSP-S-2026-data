#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<1;
		if(sr[0]==sx[0]&&sr[1]==sx[1])
		{
			cout<<1;
			char r=sr[2],x=sx[2];
			if((r>='A'&&r<='C')&&(x>='A'&&x<='C')||(r=='D'||r=='F')&&(x=='D'||x=='F'))
			{
				cout<<1;
				if(abs(r-x)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
