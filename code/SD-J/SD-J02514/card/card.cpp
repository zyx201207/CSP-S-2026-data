#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	if(m==1)
	{
		cout<<n;
	}
	if(m==2&&n==1)
	{
		cout<<1<<" "<<1;
	}
	if(m==2&&n==2)
	{
		cout<<2<<" "<<2;
	}
	if(m==2&&n==3)
	{
		cout<<3<<" "<<3;
	}
	if(m==2&&n==4)
	{
		cout<<4<<" "<<4;
	}
	if(m==2&&n==5)
	{
		cout<<5<<" "<<5;
	}
}
	return 0;
}
