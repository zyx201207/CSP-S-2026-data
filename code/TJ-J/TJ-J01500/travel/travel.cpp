#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if((sr[0]==sx[0])&&(sr[1]==sx[1]))
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	bool f=0;
	if((sr[0]==sx[0])&&(sr[1]==sx[1])&&((((sr[2]>='A')&&(sr[2]<='C'))&&((sx[2]>='A')&&(sx[2]<='C')))||(((sr[2]=='D')||(sr[2]=='F'))&&((sx[2]=='D')||(sx[2]=='F')))))
	{
		cout<<1;
		f=1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(f&&((sr[2]==sx[2]-1)||(sr[2]==sx[2]+1)||((sr[2]=='D')&&(sx[2]=='F'))||((sr[2]=='F')&&(sx[2]=='D'))))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
}
