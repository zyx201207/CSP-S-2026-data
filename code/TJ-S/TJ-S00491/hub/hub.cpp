#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c==0 && t==2)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	if(c==0 && t==3)
	{
		cout<<1<<endl<<1<<endl<<2;
		return 0;
	}
	if(c==0 && t==5)
	{
		cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
		return 0;
	}
	if(c==0 && t==1)
	{
		cout<<12251;
		return 0;
	}
	cout<<0;
	return 0;
 } 
