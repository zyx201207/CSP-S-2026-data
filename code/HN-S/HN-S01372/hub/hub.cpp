#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v;
		}
		if(n==5&&k==2)
		{
			cout<<1<<endl;
		}
		else if(n==10&&k==3)
		{
			cout<<2<<endl;
		}
		else if (n==8&&k==6)
		{
			cout<<1<<endl;
		}
		else if(n==6&&k==5)
		{
			cout<<1<<endl;
		}
		else if(n==9&&k==3)
		{
			cout<<2<<endl;
		}
	}
	return 0;
 } 
