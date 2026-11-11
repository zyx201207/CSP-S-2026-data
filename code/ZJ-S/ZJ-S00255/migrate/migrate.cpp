#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,c,n,m,a[2000001],d[2000001],sum;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>_;
	while(_--)
	{
		cin>>n>>m;
		d[1]=0,sum=0;
		cin>>a[1];
		for(int i=2;i<=n;i++) cin>>a[i],d[i]=d[i-1]+a[i]-a[i-1];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				int cnt=0;
				if(d[j]-d[i]<m) continue;
				if(d[j]-d[i]>2*m) break;
				for(int k=i;k<=j;k++)
				{
					if(d[k]-d[i]<=m&&d[j]-d[k]<=m) cnt++;
				}
				if(cnt==2) sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

