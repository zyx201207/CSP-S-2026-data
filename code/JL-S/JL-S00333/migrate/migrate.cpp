#include<bits/stdc++.h>
using namespace std;
int a[200005],s[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans=0,sum=-1e9;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=a[i]-a[i-1];
			ans=d/s[i];
			sum=max(sum,ans);
		}
	}
	cout<<sum;
	return 0;
}