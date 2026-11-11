#include<bits/stdc++.h>
using namespace std;
int xa,xb,ya,yb;
char xc,yc;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xa>>xb>>xc;
	cin>>ya>>yb>>yc;
	if(xa!=ya)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(xb!=yb)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((xc<='C'&&yc>'C')||(xc>'C'&&yc<='C'))
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(xc=='A'&&yc=='C')
	{
		cout<<"0";
		return 0;
	}
	if(xc=='C'&&yc=='A')
	{
		cout<<"0";
		return 0;
	}
	cout<<"1";
  return 0;
}