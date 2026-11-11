#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,x[200005];
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int sum=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int j=2+d;j<=n;j++)
		{
			if(d%2==0) sum++;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
