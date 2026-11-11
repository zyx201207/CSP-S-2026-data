#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{int n;
		ll m;
		cin>>n>>m;
		vector<ll>a(n+1,0);
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=4;
		ll ans=0;
		for(;r<=n;r++)
		{
			for(int i=l;i<r;i++)
			{
				if(i!=1&&a[i]!=a[i-1])
				{
				if(a[i]-a[l]<=m&&a[r]-a[i]<=m)	ans++;
				}
			}if(a[r]-a[l]<=m)ans--;
		}
		for(;l<n-3;l++)
		{
			for(int i=l;i<r;i++)
			{
				if(i!=1&&a[i]!=a[i-1])
				{
				if(a[i]-a[l]<=m&&a[r]-a[i]<=m)	ans++;
				}
			}if(a[r]-a[l]<=m)ans--;
		}
		cout<<ans/2<<'\n';
	}
}
