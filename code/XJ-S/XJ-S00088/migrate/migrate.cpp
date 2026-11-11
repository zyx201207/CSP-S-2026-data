#include<bits/stdc++.h>
using namespace std;
long long x[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(x[j]<0)
		{
			cout<<0-x[j]+1<<endl;
		}
		else
		{
			cout<<x[j]<<endl;
		}
		
	}
	
	return 0;
}
