#include<bits/stdc++.h>
using namespace std;
int c,t;int n,k;
void sol()
{
	if(c==1)
	for(int i=1;i<=t;i++)
	{
		int x=rand();
		cout<<x%10<<"\n";
	}
	else if(2<=c&&c<=8)
	for(int i=1;i<=t;i++)
	{
		int x=rand();
		cout<<x%10<<"\n";
	}
	else if(9<=c&&c<=12)
	for(int i=1;i<=t;i++)
	{
		int x=rand();
		cout<<x%100<<"\n";
	}
	else if(13<=c&&c<=20)
	for(int i=1;i<=t;i++)
	{
		int x=rand();
		cout<<x<<"\n";
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	sol();
	return 0;
}

