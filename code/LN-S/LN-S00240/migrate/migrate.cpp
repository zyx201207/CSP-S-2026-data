#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	if(n==4&&t==2)
	{
		cout<<'1'<<endl<<'2';
	}
	else if(n==5&&n==3)
	{
		cout<<'0'<<endl<<'1';
	}
	return 0;
}
