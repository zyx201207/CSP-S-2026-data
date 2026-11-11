#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cf,sf,cs,ss;
	cin>>cf>>sf>>cs>>ss;
	if(cf==cs) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	} 
	if(sf[0]==ss[0]&&sf[1]==ss[1])
	{
		cout<<"1";
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if(sf[2]<='C'&&ss[2]<='C')
	{
		cout<<"1";
	}
	else if(sf[2]>='D'&&ss[2]>='D')
	{
		cout<<"1";
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if((sf[2]=='D'&&ss[2]=='F')||(ss[2]=='D'&&sf[2]=='F'))
	{
		cout<<"1\n";
	}
	else if(sf[2]<ss[2]&&sf[2]+1==ss[2])
	{
		cout<<"1\n";
	}
	else if(sf[2]>ss[2]&&sf[2]-1==ss[2])
	{
		cout<<"1\n";
	}
	else cout<<"0\n";
	return 0;
}