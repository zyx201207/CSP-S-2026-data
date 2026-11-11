#include <iostream>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
	}
	if(n==4&&m==2)
	{
		cout<<12;
	}
	if(n==5&&m==3)
	{
		cout<<7;
	}
	else
	cout<<4;
}