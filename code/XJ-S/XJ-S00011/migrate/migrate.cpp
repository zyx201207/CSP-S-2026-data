#include<bits/stdc++.h>
using namespace std;
int a[4000005],sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,t,s,c,i,j,k;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>s;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int sum=1;
		m=a[sum]-a[sum+1];
		if(s==m)
		{
			cout<<0<<endl;
			continue;
		}
		if(s>m&&s<2*m)
		{
			cout<<0<<endl;
			continue;
		}
		if(s==2*m)
		{
			cout<<1<<endl;
			continue;
		}
		if(s>2*m&&s<3*m)
		{
			cout<<1<<endl;
			continue;
		}
		if(s>=3*m)
		{
			cout<<0<<endl;
		}
	}	
	return 0;
} 
