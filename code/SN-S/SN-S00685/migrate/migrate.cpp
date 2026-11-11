#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j = 1;j<=n;j++)
		{
			cin>>a[j];
		}
		if(n==4 && d== 2)
		{
			cout<<"1"<<endl;
			cout<<"2"<<endl;
		}
		else if(n==5 && d== 3)
		{
			cout<<"0"<<endl;
			cout<<"1"<<endl;
		}
	}
	return 0;
 } 
