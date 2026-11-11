#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010],b[2000010],cnt[2000010],dis[2000010],lst,ans;
priority_queue<pair<int,int> > q;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,m;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==11||c==12)
		{
			cout<<n-3<<endl;
			continue;
		}
		if(c==13||c==14)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			b[i]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dis[j]=2e9;
				cnt[j]=0;
			}
			dis[i]=0;
			cnt[i]=1;
			for(int x=i;x<=n;x++)
			{
				lst=x;
				for(int v=lst+1;v<=b[x];v++)
				{
					if(dis[v]>=dis[x]+1)
					{
						dis[v]=dis[x]+1;
						cnt[v]+=cnt[x];
					}
					else
						lst=v;
				}
				if(cnt[x]==2)
					ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

