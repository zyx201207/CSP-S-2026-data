#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000"<<"\n";
		return 0;
	}
	if(sr[0]==sx[0] && sr[1]==sx[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000"<<"\n";
		return 0;
	}
	int tr=sr[2]-'A',tx=sx[2]-'A';
	if((tr<=2 && tx<=2) || ((tr>2 && tr<=4) && (tx>2 && tx<=4)))
	{
		cout<<1;
	}
	else
	{
		cout<<"00"<<"\n";
		return 0;
	}
	if(abs(tr-tx)==1)
	{
		cout<<1<<"\n";
	}
	else
	{
		cout<<0<<"\n";
	}
	return 0;
}
