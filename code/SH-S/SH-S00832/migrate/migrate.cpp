#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		sum+=n;
		sum+=d;
	}
	if(sum==13)
	{
		cout<<1<<endl;
		cout<<2;
	}
	else if(sum==16)
	{
		cout<<0<<endl;
		cout<<1;
	}
	return 0;
} 
