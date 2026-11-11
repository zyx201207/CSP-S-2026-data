#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int y,o,i=1,u,p;
	cin>>y>>u>>o>>p;
	if(y==o)
	{
		cout<<"1";		
	}
	else
	{
		cout<<"0";
	}
	if(u==p+1||u==p-1)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(u==p+1||u==p-1)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(u==p+1||u==p-1)
	{
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}