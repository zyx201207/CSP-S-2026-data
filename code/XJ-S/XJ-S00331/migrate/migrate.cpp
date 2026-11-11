#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll ans,js,ju;
ll n,m;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		if (n<=3)
		{
			cout<<"0"<<endl;
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int cnt=0;
		for (int i=1;i<=n-3;i++)
		{
			if (a[i+3]-a[i]<m)
			{
				cnt++;
			}
		}
		if (cnt==n-3)
		{
			cout<<"0"<<endl;
			continue;
		}
		cnt=0;
		for (int i=2;i<=n;i++)
		{
			if (a[i]-a[i-1]>m)
			{
				cnt++;
			}
		}
		if (cnt==n-1)
		{
			cout<<"0"<<endl;
			continue;
		}
		int x=a[2]-a[1],f=0;
		for (int i=3;i<=n;i++)
		{
			if (a[i]-a[i-1]!=x)
			{
				f=1;
				break;
			}
		}
		if (f==0)
		{
			cout<<n-3<<endl;
			continue;
		}
		for (int i=1;i+3<=n;i++)
		{
			if (a[i+3]-a[i+1]<=m && a[i+1]-a[i]<=m && a[i+2]-a[i]<=m && a[i+3]-a[i+2]<=m)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0; 
} 
//****xxf
//.....zzzz 
