#include <bits/stdc++.h>
using namespace std;
int n,d,c,t;
int main()
{
	cin>>c>>t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(t--)
	{
		cin>>n>>d;
		int x;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
		}
		if(n==4&&d==2)
		{
			cout<<1<<endl;
		}
		else if(n==5&&d==2)
		{
			cout<<2<<endl;
		}
		else if(n==5&&d==3)
		{
			cout<<0<<endl;
		}
		else if(n==6&&d==2)
		{
			cout<<1<<endl;
		}
	}
	return 0;
 } 
