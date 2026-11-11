#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cha,chb;
	string sa,sb;
	cin >>cha >> sa;
	cin >> chb >> sb;
	if(cha == chb)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(sa[0] == sb[0] && sa[1] == sb[1])
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if((sa[2]<='C'&&sb[2]<='C')||(sa[2]>='D'&&sb[2]>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(sa[2]-sb[2])==1||(sa[2]=='D'&&sb[2]=='F')||(sa[2]=='F'&&sb[2]=='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
