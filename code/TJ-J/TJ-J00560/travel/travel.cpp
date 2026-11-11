#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,bx,an,bn;
	cin>>ax>>an>>bx>>bn; 
	
	if(ax==bx)
	{
		cout<<1;
	} 
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int ap=0,bp=0;
	int al,bl;
	ap=int(an[0]-'0')*10+int(an[1]-'0');
	bp=int(bn[0]-'0')*10+int(bn[1]-'0');
	al=an[2]-'A'+1;
	bl=bn[2]-'A'+1;
	if(ap==bp) 
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if((al<=3&&bl<=3)||(al>3&&bl>3)) cout<<1;
	else
	{
		cout<<0<<0;
		return 0;
	}
	if(al+1==bl||al-1==bl)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0; 
 } 
