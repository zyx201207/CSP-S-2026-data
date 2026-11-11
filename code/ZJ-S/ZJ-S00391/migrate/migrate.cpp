#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005];
pair<int,int>dfs(int i,int j)
{
	int mi=1e18,an=0;
	for(int k=i+1;k<=b[i]&&k<=j;k++)
	{
		pair<int,int>th=dfs(k,j);
		if(th.first<mi-1)an=0,mi=th.first+1;
		an+=th.second;
	}
	return{mi,an};
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n,t,d,sum=0;
	cin>>c>>t;
	if(c>10)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=0;i<n;i++)cin>>a[i];
			d/=a[1]-a[0];
			cout<<max(d-1,0ll)*(n-2*d+2)<<'\n';
		}
		return 0;
	}
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)
		{
			b[i]=i;
			for(int j=i+1;j<n&&a[j]-a[i]<=d;j++)b[i]=j;
		}
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)ans+=dfs(i,j).second==2;
		cout<<ans<<'\n';
	}
	return 0;
}